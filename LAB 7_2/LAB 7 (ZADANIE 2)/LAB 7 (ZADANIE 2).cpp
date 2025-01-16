#include <iostream>
using namespace std;
double power(double x, int n) {
    if (n == 0) return 1; 

    if (n % 2 == 0) {  // Если n четное
        double half = power(x, n / 2);
        return half * half;
    }
    else {  // Если n нечетное
        return x * power(x, n - 1);
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    double x;
    int n;

    cout << "Введите число x: ";
    cin >> x;

    cout << "Введите степень n: ";
    cin >> n;

    double result = power(x, n);
    cout << "Результат: " << result << endl;

    return 0;
}