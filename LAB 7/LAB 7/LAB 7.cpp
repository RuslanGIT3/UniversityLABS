#include <iostream>
#include <set>
using namespace std;
bool hasUniqueDigits(int number) {
    set<int> digits;  
    while (number > 0) {
        int digit = number % 10;  
        if (digits.count(digit)) {  
            return false;
        }
        digits.insert(digit);  
        number /= 10;  
    }
    return true;  
}

int main() {
    setlocale(LC_ALL, "RU");
    int n; 
    cout << "Введите количество чисел: ";
    cin >> n;

    int numbers[100]; 
    cout << "Введите числа: ";
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    int count = 0;  
    for (int i = 0; i < n; ++i) {
        if (hasUniqueDigits(numbers[i])) {
            count++;
        }
    }

    cout << "Количество чисел с уникальными цифрами: " << count << endl;
    return 0;
}