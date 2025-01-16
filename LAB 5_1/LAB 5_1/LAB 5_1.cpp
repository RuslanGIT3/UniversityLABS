#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "RU");
    int n;
    cout << "Введите количество отрезков: ";
    cin >> n;
    int* a = new int[n];
    int* b = new int[n];
    cout << "Введите границы отрезков (ai и bi): " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Отрезок " << i + 1 << ": ";
        cin >> a[i] >> b[i]; 
    }

    int maxLength = 0;  // Для хранения максимальной длины отрезка 
    int maxIndex = -1;  // Индекс отрезка с максимальной длиной

    for (int i = 0; i < n; i++) {
        int length = b[i] - a[i];  
        if (length > maxLength) {
            maxLength = length;  
            maxIndex = i;        
        }
    }

    if (maxIndex != -1) {
        cout << "Максимальный отрезок: [" << a[maxIndex] << ", " << b[maxIndex] << "] с длиной " << maxLength << endl;
    }
    else {
        cout << "Нет отрезков." << endl;
    }

    delete[] a;
    delete[] b;

    return 0;
}
