#include <iostream>
#include <string>

using namespace std;

// Структура "Адрес"
struct Address {
    string street;     // Улица
    int houseNumber;   // Номер дома
    int apartmentNumber; // Номер квартиры
};

// Структура "Житель"
struct Resident {
    string name;        // Ф.И.О.
    Address address;    // Адрес
    char gender;        // Пол ('M' - мужской, 'F' - женский)
    int age;            // Возраст
};

void countResidentsInHouse(Resident residents[], int n, int houseNumber) {
    int maleCount = 0;
    int femaleCount = 0;

    for (int i = 0; i < n; ++i) {
        if (residents[i].address.houseNumber == houseNumber) {
            if (residents[i].gender == 'M') {
                maleCount++;
            }
            else if (residents[i].gender == 'F') {
                femaleCount++;
            }
        }
    }

    cout << "В доме номер " << houseNumber << " проживает:\n";
    cout << "Мужчин: " << maleCount << endl;
    cout << "Женщин: " << femaleCount << endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    // Массив жителей (фрагмент базы данных)
    Resident residents[] = {
        {"Дедин Марат Кукловодович", {"Казинца", 10, 5}, 'M', 30},
        {"Ступакова Витория Александровна", {"Казинца", 10, 5}, 'F', 25},
        {"Мартусин Руслан Юрьевичь", {"Советская", 12, 3}, 'M', 45},
        {"Рутковская Виктория Максимовна", {"Казинца", 10, 5}, 'F', 40},
        {"Морозов Сергей Николаевич", {"Советская", 12, 3}, 'M', 50},
        {"Трубилова Дарья Юрьевна", {"Казинца", 15, 7}, 'F', 35}
    };

    int n = sizeof(residents) / sizeof(residents[0]); // Количество жителей в массиве

    int houseNumber;
    cout << "Введите номер дома для подсчета: ";
    cin >> houseNumber;

    countResidentsInHouse(residents, n, houseNumber);

    return 0;
}
