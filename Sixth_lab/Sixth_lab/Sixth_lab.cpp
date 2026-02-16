#include <iostream>
#include <cmath>
#include <locale.h>
using namespace std;

double integra(double b, double a, int n) {
	double inteB;
	double inteA;
	if (n == 1) {
		return (-1 * cos(b) - (-1) * cos(a));
	}
	else if (n == 2) {
		inteB = ((b / 2) - (sin(2 * b) / 4));
		inteA = ((a / 2) - (sin(2 * a) / 4));
		return inteB - inteA;
	}
	else if (n > 2) {
		double integral = integra(b, a, n - 2);
		double nn = (n-1.0)/n;

		double interB = (-(pow(sin(b), n - 1) * cos(b)) / n);
		double interA = (-(pow(sin(a), n - 1) * cos(a)) / n);

		return (interB - interA) + nn * integral;
	}
}


int main() {
	setlocale(LC_ALL, "rus");
	double a, b;
	int n;

	cout << "Введите границу верхнего предела b: "; cin >> b; 
	cout << "Введите границу нижнего предела a: "; cin >> a; 
	cout << "Введите положительную степень n: "; cin >> n; 
	if (n < 1) cout << "Степень n должна быть больше нуля!";
	else cout << "Значение интеграла = " << integra(b, a, n);

	return 0;
}