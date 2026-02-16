#include <iostream>
#include <locale.h>
#include <cmath>

using namespace std;
double baseArea(double base) {
	return base * base;
}
double sideArea(double side, double base) {
	double h = sqrt((side * side) - ((base / 2) * (base / 2)));
	return (h * base) / 2;
}

int main() {
	setlocale(LC_ALL, "rus");
	int n = 4;
	double base, side;
	while (true) {
		cout << "¬ведите длину стороны основани€ пирамиды: "; cin >> base;
		cout << "¬ведите длину боковой стороны пирамиды: "; cin >> side;
		if (side > base / 2) {
			break;
		}
		cout << "Ѕокова€ сторона должна быть больше половины стороны основани€!" << endl;
	}

	double area = baseArea(base) + 4 * sideArea(side, base);
	cout << "ѕлощадь полной поверхности правильной пирамиды: " << area;

	return 0;
}