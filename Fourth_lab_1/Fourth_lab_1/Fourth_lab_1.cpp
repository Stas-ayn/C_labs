#include <iostream>
#include <locale.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int rez = 0, n;
	double r1, r2, x, y;
	cout << "¬ведите радиус внутренней окружности: ";
	cin >> r1;
	cout << "¬ведите радиус внешней окружности: ";
	cin >> r2;
	cout << "¬ведите количество точек: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "¬ведите координаты точки: ";
		cin >> x >> y;
		double dist = sqrt(x * x + y * y);
		if (dist > r1 && dist < r2) rez++;
	}
	cout << "ќтвет: " << rez;
	return 0;
}
