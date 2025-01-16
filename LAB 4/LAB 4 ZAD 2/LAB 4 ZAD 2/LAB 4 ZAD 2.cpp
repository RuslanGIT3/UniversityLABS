#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    setlocale(LC_ALL, "RU");
    const int rows = 8, cols = 3;
    int array[rows][cols];
    double average;
    double sum = 0.0;
    srand(time(0));


    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = static_cast<double>(rand()) / RAND_MAX * 100.0; //array[i][j] = (rand() / (RAND_MAX + 1.0)) * 100.0;
            sum += array[i][j];
        }
    }
    
    average = (sum) / (rows * cols);//ср арифметичческое

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Среднее арифметическое: " << average << endl;
    return 0;

}
