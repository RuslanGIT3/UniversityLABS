#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <Windows.h>
using namespace std;
void infile() {
    string sotrudnik[7]; 
    cout << "Введите фио содрудника" << endl;
    cin >> sotrudnik[0] >> sotrudnik[1] >> sotrudnik[2];
    cout << "Введите дату приёма на работу" << endl;
    cin >> sotrudnik[3];
    cout << "Введите должность сотрудника" << endl;
    cin >> sotrudnik[4];
    cout << "Введите базовый оклад сотрудника"<<endl;
    cin >> sotrudnik[5];
    ofstream out;          
    out.open("Sotrudnik.txt");
    for (int i=0; i < 6;i++) {
        out << sotrudnik[i];
        out<<" ";
        
    }
    out.close();
    system("cls");
}
void outfile() {
    string n;
    ifstream in("Sotrudnik.txt");
    std::getline(in, n);
    
      string word[7];
      istringstream words(n);
      int i = 0;
      string tutu;
      while (words >> tutu) {
          word[i] = tutu;
          if (i > 2) {
              cout << endl;
          }
          cout << word[i]<<" ";
          i++;
      }
}

int main()

{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(0, "ru");
    infile();
    outfile();
   


    return 0;
}

