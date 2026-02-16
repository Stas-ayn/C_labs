#include <iostream>
#include <locale.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int rows;
	double trace = 0;
	double arr[10][10];
	cout << "¬ведите количество строк квадратной матрицы: "; cin >> rows;
	cout << "¬ведите элементы матрицы: ";
	for (int i= 0; i < rows; i++) {
		for (int j=0; j < rows; j++) {
			cin >> arr[i][j];
			if (i == j) {
				trace += arr[i][j];
			}
		}
	}


	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			if (i!= j) {
				cout << (arr[i][j] - trace) << " ";
			}
		}
		cout << endl;
	}
	cout << "—лед матрицы: "<<trace;
	

	return 0;
}