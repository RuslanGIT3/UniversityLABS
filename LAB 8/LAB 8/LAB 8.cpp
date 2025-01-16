#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Функция для разделения текста на предложения
void splitSentences(const string& text) {
    int sentenceCount = 0;
    string sentence = "";

    // Обрабатываем каждую букву в тексте
    for (int i = 0; i < text.length(); ++i) {
        char c = text[i];
        if (c == '.') {
            if (!sentence.empty()) {
                sentenceCount++;
                cout << "Предложение " << sentenceCount << ": " << sentence << endl;
                sentence = ""; 
            }
        }
        else {
            sentence += c;  
        }
    }

    cout << "Количество предложений: " << sentenceCount << endl;
}

// Функция для подсчёта слов в предложении
void countWordsInFirstSentence(const string& sentence) {
    int wordCount = 0;
    bool inWord = false;

    // Подсчитываем количество слов в предложении
    for (int i = 0; i < sentence.length(); ++i) {
        char c = sentence[i];
        if (c == ' ' || c == '.') {
            if (inWord) {
                wordCount++;
                inWord = false;
            }
        }
        else {
            inWord = true;
        }
    }
    if (inWord) wordCount++;  // для последнего слова, если оно есть

    cout << "Количество слов в первом предложении: " << wordCount << endl;

    // Выводим четные слова
    cout << "Четные слова в первом предложении: ";
    int wordIndex = 1;
    string word = "";
    for (int i = 0; i < sentence.length(); ++i) {
        char c = sentence[i];
        if (c == ' ' || c == '.') {
            if (!word.empty()) {
                if (wordIndex % 2 == 0) {
                    cout << word << " ";
                }
                wordIndex++;
                word = "";
            }
        }
        else {
            word += c;  // собираем слово
        }
    }
    if (!word.empty() && wordIndex % 2 == 0) {
        cout << word << " ";  // для последнего слова
    }
    cout << endl;
}

// Функция для перевода числа в пятнадцатеричную систему
void decimalToHexadecimal(int number) {
    if (number == 0) {
        cout << "0";
        return;
    }

    string hexChars = "0123456789ABCDEF";
    string hex = "";
    while (number > 0) {
        hex = hexChars[number % 15] + hex;
        number /= 15;
    }
    cout << hex;
}

// Функция для перевода первого числа в пятнадцатеричную систему
void convertFirstNumberToHex(const string& sentence) {
    int number = 0;
    bool numberFound = false;

    // Ищем первое число в предложении
    for (int i = 0; i < sentence.length(); ++i) {
        char c = sentence[i];
        if (c >= '0' && c <= '9') {  // если символ цифра
            number = number * 10 + (c - '0');
            numberFound = true;
        }
        else if (numberFound) {
            break;  // если уже нашли число и встретился нецифровой символ, выходим
        }
    }

    if (numberFound) {
        cout << "Первое число в пятнадцатеричной системе: ";
        decimalToHexadecimal(number);
        cout << endl;
    }
    else {
        cout << "Число не найдено в первом предложении." << endl;
    }
}

// Функция для перевода предложения в обратном порядке
void printSentenceInReverse(string sentence) {
    reverse(sentence.begin(), sentence.end());
    cout << "Предложение в обратном порядке: " << sentence << endl;
}

// Функция для вычисления характеристики слова (максимальная длина серии одинаковых символов)
int wordCharacteristic(const string& word) {
    int maxSeries = 1, currentSeries = 1;
    for (size_t i = 1; i < word.length(); ++i) {
        if (word[i] == word[i - 1]) {
            currentSeries++;
            maxSeries = max(maxSeries, currentSeries);
        }
        else {
            currentSeries = 1;
        }
    }
    return maxSeries;
}

// Функция для сортировки слов по характеристикам (по длине самой длинной серии одинаковых символов)
void sortWordsByCharacteristic(string& sentence) {
    string words[100];  // Массив для хранения слов
    int wordCount = 0;
    string word = "";

    // Разбиваем предложение на слова
    for (int i = 0; i < sentence.length(); ++i) {
        char c = sentence[i];
        if (c == ' ' || c == '.') {
            if (!word.empty()) {
                words[wordCount++] = word;
                word = "";
            }
        }
        else {
            word += c;  // собираем слово
        }
    }
    if (!word.empty()) {
        words[wordCount++] = word;  // для последнего слова
    }

    // Сортировка слов
    for (int i = 0; i < wordCount - 1; ++i) {
        for (int j = i + 1; j < wordCount; ++j) {
            if (wordCharacteristic(words[i]) > wordCharacteristic(words[j])) {
                swap(words[i], words[j]);
            }
        }
    }

    // Вывод отсортированных слов
    cout << "Слова отсортированные по характеристикам: ";
    for (int i = 0; i < wordCount; ++i) {
        cout << words[i] << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "RU");

    string text;

    // Ввод текста
    cout << "Введите текст: ";
    getline(cin, text);

 
    splitSentences(text);

 
    string firstSentence = text.substr(0, text.find('.'));
    countWordsInFirstSentence(firstSentence);

   
    convertFirstNumberToHex(firstSentence);

    // 4. Выводим первое предложение в обратном порядке
    printSentenceInReverse(firstSentence);

    // 5. Сортируем слова первого предложения по характеристикам
    sortWordsByCharacteristic(firstSentence);

    return 0;
}
