#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double a = -2;
    double b = -0.1;
    double h = (b - a) / 10;
    for (double x = a; x <= b; x += h) {
        double y = log(1 / (2 + 2 * x + x * x));
        double s = 0;
        int n = 1;
        while (n <= 160) {
            s += pow(-1, n) * pow(1 + x, 2 * n) / (n);
            n++;
        }
        cout << "x=" << x << "; Y(x)=" << y << "; S(x)=" << s << endl;
    }
    return 0;
}