#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "RU");
    const int k = 10;
    char arr[k];
    cout << "Введите " << k << " символов: ";
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }
    int index = 0;
    for (int i = 0; i < k; i++) {
        bool isun = true;
        for (int j = 0; j < index; j++) {
            if (arr[i] == arr[j]) {
                isun = false;
                break;
            }
        }
        if (isun) {
            arr[index++] = arr[i]; 
        }
    }
    cout << "Массив без повторяющихся символов: ";
    for (int i = 0; i < index; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
