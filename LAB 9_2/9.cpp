
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <Windows.h>

using namespace std;
void zapis() {
	vector<string>
	ofstream out;
	out.open("Da.txt");
	out
}
int main()
{
	setlocale(0, "RU");
	string s;
	vector<string> v;
	ifstream file("Da.txt");
	int i = 0;
	for (file >> s; !file.eof(); file >> s) {
		cout << s << endl;
		v[i] = s;
		i++;
	}
}

