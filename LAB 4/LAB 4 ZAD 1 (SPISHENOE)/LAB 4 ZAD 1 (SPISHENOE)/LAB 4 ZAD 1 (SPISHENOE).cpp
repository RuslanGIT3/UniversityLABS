#include <iostream>
#include <cmath>
using namespace std;
int main() {
    setlocale(LC_ALL, "Ru");
    int n;
    cout << "Кол-во элементов: ";
    cin >> n;
    int a[100]; // Массив 
    for (int i = 0; i < n; i++) { // ввод элементов в массив
        cout << "Введите элементы: ";
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) { // вывод элементов в консоль
        cout << a[i] << " ";
    }

}