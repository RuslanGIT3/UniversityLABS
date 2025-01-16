#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "RU");
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    int a[1000]; 
    for (int i = 0; i < n; i++) {
        cout << "Введите элемент  " << (i + 1) << ": ";
        cin >> a[i];
    }
    cout << "Элементы массива: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    int unique_el = 0;
    for (int i = 0; i < n; i++) {
        bool isUnique = true;
        for (int j = 0; j < i; j++) {
            if (a[i] == a[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) unique_el ++;
    }
    cout << "Количество различных элементов: " << unique_el << endl;
    return 0;
}
