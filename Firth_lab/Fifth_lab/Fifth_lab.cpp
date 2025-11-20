#include <iostream>
#include <locale.h>
using namespace std;

int max(double a, double b) {
	double c;
	if (a > b) c = a;
	else c = b;
	return c;
}


int main() {
	setlocale(LC_ALL, "rus");

	double a, b, u, v, rez;
	cout << "Введите a и b: ";
	cin >> a >> b;
	u = max(a, b);
	v = max(a * b, a + b);

	rez = max(u + v * v, 3.14);
	cout << "Ответ: " << rez;
	return 0;
}