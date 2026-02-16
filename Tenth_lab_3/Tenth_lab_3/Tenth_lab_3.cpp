#include <iostream>
#include <locale.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

double perm(int x) {
	double y = sin(exp(x));
	y = round(y * 1000000) / 1000000;
	return y;
}

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));

	int n;
	while (true) {
		cout << "Введите количество элементов n > 20: "; cin >> n;
		if (n > 20) {
			break;
		}
		cout << "Элементов должно быть больше 20!" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}

	int* arrX = new int[n];
	double* arrY = new double[n];
	for (int i = 0; i < n; i++) {
		arrX[i] = rand() % 21 - 10;
	}
	cout << "Массив X: ";
	for (int i = 0; i < n; i++) {
		cout << arrX[i] << " ";
		arrY[i] = perm(arrX[i]);
	}
	cout << "\n";
	int count = 0;
	cout << "Массив Y: ";
	for (int i = 0; i < n; i++) {
		cout << arrY[i] << " ";
		if (i % 2 != 0 && arrY[i] < 0) {
			count += 1;
		}
	}
	cout << endl;
	cout << "Количество отрицательных элементов с нечетными индексами: " << count;



	delete[] arrX;
	delete[] arrY;

	return 0;
}