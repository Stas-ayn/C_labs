#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
int findd(double* arr, int n, double targ) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == targ) {
			return i;
		}
	}
	return -1;
}

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int n, a, b;
	while (true) {
		cout << "Введите размер массива: "; cin >> n;
		if (n > 0) {
			break;
		}
		cout << "Число элементов должно быть больше нуля!" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}

	double* arr = new double[n];
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 101 - 50;
	}
	cout << "Сгенерированный массив: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	int indexA, indexB;
	while (true) {
		indexA = -1; indexB = -1;
		cout << "Введите элемент границы A: "; cin >> a;
		cout << "Введите элемент границы B: "; cin >> b;

		for (int i = 0; i < n; i++) {
			if (a == arr[i]) {
				indexA = i;
			}
			if (b == arr[i]) {
				indexB = i;
			}
		}
		if (indexA == -1 || indexB == -1) {
			cout << "Данного элемента нет в массиве!" << endl;
			continue;
		}
		if (indexA >= indexB) {
			cout << "Граница A должна стоять раньше B!" << endl;

		}
		if (indexA < indexB) {
			cout << "Количество элементов в диапазоне: " << indexB - indexA - 1<< endl;
			break;
		}
	}

	double* m = min_element(arr, arr + n);
	double minn = *m;
	cout << "Минимальный элемент массива: "<< minn << endl;
	double sum = 0;
	int min_index = findd(arr, n, minn);
	for (int i = min_index + 1; i < n; i++) {
		sum += arr[i];
	}
	cout << "Сумма элементов после минимального элемента: " << sum;
	delete[] arr;
	return 0;
}