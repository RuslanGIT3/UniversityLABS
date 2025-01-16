#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <Windows.h>
using namespace std;
void infile() {
    string M2[18]; 
    cout << "Название фильма" << endl;
    cin >> M2[0] >> M2[1] >> M2[2];
    cout << "Год выпуска" << endl;
    cin >> M2[3] >> M2[4] >> M2[5];
    cout << "Длительность" << endl;
    cin >> M2[6] >> M2[7] >> M2[8];
    cout << "Тип пленки"<<endl;
    cin >> M2[9] >> M2[10] >> M2[11];
    cout << "Студия" << endl;
    cin >> M2[12] >> M2[13] >> M2[14];
    cout << "Актеры" << endl;
    cin >> M2[15] >> M2[16] >> M2[17];
    ofstream out;          
    out.open("M2.txt");
    for (int i=0; i < 6;i++) {
        out << M2[i];
        out<<" ";
        
    }
    out.close();
    system("cls");
}
void outfile() {
    string n;
    ifstream in("M2.txt");
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

