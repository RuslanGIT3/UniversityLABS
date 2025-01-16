#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    setlocale(LC_ALL, "RU");
    double Deposit = 1000.0;
    double targetAmount = 1100.0;
    double rate;
    int months = 0;
    cout << "Введите процент P(0<P<25): ";
    cin >> rate;
    if (rate <= 0 || rate >= 25) {
        cout << "Ошибка, процент должен быть в диапазоне (0-25)";
        return 1;
    }
    rate /= 100.0; //rate=rate/100
    double currentAmount = Deposit;
    while (currentAmount <= targetAmount) {
        currentAmount *= (1 + rate);
        months++;
    }
    cout << "Количество месяцев: " << months << endl;
    cout << fixed << setprecision(2);
    cout << "Итоговый размер вклада: " << currentAmount << " руб" << endl;
    return 0;
}