#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void Min4islo (int N, int M, int matrix[10][10]) {
    cout << "Минимальные элементы в каждом столбце:" << endl;
    for (int j = 0; j < M; j++) {
        int min = matrix[0][j];
        for (int i = 1; i < N; i++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j]; 
            }
        }
        cout << "Столбец " << j + 1 << ": " << min << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    srand(static_cast<unsigned int>(time(nullptr)));

    int N, M;
    cout << "Введите количество строк (N): ";
    cin >> N;
    cout << "Введите количество столбцов (M): ";
    cin >> M;

    int matrix[10][10]; 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrix[i][j] = rand() % 100;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    Min4islo (N, M, matrix);
    return 0;
}
