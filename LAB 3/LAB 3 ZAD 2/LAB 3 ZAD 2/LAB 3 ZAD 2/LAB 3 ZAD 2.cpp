#include <iostream>
#include <cmath>
using namespace std;
int main() {
    setlocale(LC_ALL, "RU");
    double Startsum = 24.0; 
    double rate = 0.06; 
    int start_year = 1826;       
    int end_year = 2024;           
    double total_amount = Startsum;
    for (int year = start_year; year < end_year; year++) {
        total_amount += total_amount * rate; 
    }
    cout << "Состояние счета в 2024 году: $" << total_amount << endl;
    return 0;
}
