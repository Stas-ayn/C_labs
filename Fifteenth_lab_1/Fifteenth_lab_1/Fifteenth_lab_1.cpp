#include <iostream>
#include <fstream>
#include <cstdio>
#include <Windows.h>
#include <string>
using namespace std;


//Подход си
//int main() {
//	SetConsoleCP(65001);
//	SetConsoleOutputCP(65001);
//
//	int digs[4];
//	double rezs[2];
//	char opers[2];
//	FILE* file;
//	errno_t err = fopen_s(&file, "forFifteenthLab.txt", "r");
//	if (err != 0) {
//		return 1;
//	}
//	int cher;
//	while ((cher = getc(file)) != EOF) {
//		putchar(cher);
//	}
//	rewind(file);
//	cout << endl << '\n';
//	
//	int curr_num = 0, strike = 0, count_digs = 0, count_opers = 0;
//	while ((cher = getc(file)) != EOF) {
//		if (isdigit(cher) ) {
//			curr_num = curr_num * 10 + (cher - '0'); // символ нуля имеет ASCII код 48, и поэтому при вычитании его из кода любой другой цифры, получится нужная цифра
//			strike = 1;
//		}
//		else {
//			if (strike) {
//				digs[count_digs] = curr_num; count_digs++;
//				strike = 0;
//				curr_num = 0;
//			}
//		}
//
//	}
//	rewind(file);
//	while ((cher = getc(file)) != EOF) {
//		if (strchr("+-*/", cher)) {
//			switch (cher) {
//			case '+': opers[count_opers] = '+'; rezs[count_opers] = digs[(2 * count_opers)] + digs[(2 * count_opers) + 1];  break;
//			case '-': opers[count_opers] = '-'; rezs[count_opers] = digs[(2 * count_opers)] - digs[(2 * count_opers) + 1]; break;
//			case '*': opers[count_opers] = '*'; rezs[count_opers] = digs[(2 * count_opers)] * digs[(2 * count_opers) + 1]; break;
//			case '/': opers[count_opers] = '/'; rezs[count_opers] = digs[(2 * count_opers)] / (digs[(2 * count_opers) + 1] * 1.0); break;
//			}
//			count_opers++;
//		}
//	}
//
//	cout << digs[0] << " " << opers[0] << " " << digs[1] << " = " << rezs[0] << endl;
//	cout << digs[2] << " " << opers[1] << " " << digs[3] << " = " << rezs[1] << endl;
//
//
//
//
//
//	fclose(file);
//	return 0;
//}


// подход си++
int main() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	int x, y, n, k;
	double rez1, rez2;
	char oper1, oper2;
	string line, text;
	ifstream input("forFifteenthLab.txt");
	while (getline(input, line)) {
		cout << line << endl;
	}
	input.clear();
	input.seekg(0); 


	input >> text >> text >> text >> text >> text;
	input >> x >> oper1 >> y;
	input.ignore(1000, '\n');
	input >> text >> text >> text >> text >> text;
	input >> n >> oper2 >> k;
	
	switch (oper1) {
	case '+': rez1 = x + y; break;
	case '-': rez1 = x - y; break;
	case '*': rez1 = x * y; break;
	case '/': rez1 = x / y; break;
	}
	switch (oper2) {
	case '+': rez2 = n + k; break;
	case '-': rez2 = n - k; break;
	case '*': rez2 = n * k; break;
	case '/': rez2 = n / k; break;
	}

	cout << x << " " << oper1 << " " << y << " = " << rez1 << endl;
	cout << n << " " << oper2 << " " << k << " = " << rez2 << endl;

	return 0;
}