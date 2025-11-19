#include <iostream>
#include <locale.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	const double Na = 6.022e23, R = 8.31;
	double V = 4.5e-4, P = 2.5e4, T = 283;

	for (int i = 1; i <= 6; i++) {
		double v = (P * V) / (R * T);
		double N = Na * v;
		cout << "Число молекул при температуре " << T - 273 << ": " << N << endl;
		T = T + 2;
	}

	return 0;
}