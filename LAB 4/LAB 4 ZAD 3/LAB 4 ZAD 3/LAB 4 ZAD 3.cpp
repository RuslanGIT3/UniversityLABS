#include <iostream>
#include <limits>
using namespace std;
int main() {
    setlocale(LC_ALL, "RU");
    const int size = 4;
    int matrix[size][size];
    cout << "Введите элементы матрицы " << size << "x" << size << ":\n";
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            cin >> matrix[i][j];
    int maxElement = matrix[0][0];
    int maxRow = 0;
    for (int i = 0; i < size; i++) {
        if (matrix[i][i] > maxElement) {
            maxElement = matrix[i][i];
            maxRow = i;
        }
    }
    for (int j = 0; j < size; j++) {
        if (j != maxRow) matrix[maxRow][j] = 0; // Заменяем строку
    }
    for (int i = 0; i < size; i++) {
        if (i != maxRow) matrix[i][maxRow] = 0; // Заменяем столбец
    }
    cout << "Изменённая матрица:\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
    return 0;
}
