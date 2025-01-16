#include <iostream>
#include <cmath>
using namespace std;
int main() {
    setlocale(LC_ALL, "RU");
    double a;
    int N;
    cout << "Введите вещественное число: ";
    cin >> a;
    cout << "Введите целое число(N>0): ";
    cin >> N;
    if (N <= 0) {
        cout << "N должен быть больше 0!" << endl;
        return 1;
    }
    for (int i = 1; i <= N; ++i) {
        double result = pow(a, i);
        cout << a << "^" << i << "=" << result << endl;
    }
    return 0;

}