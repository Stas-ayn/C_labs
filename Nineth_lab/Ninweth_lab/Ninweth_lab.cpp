#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>
using namespace std;

int binSearch(int x, int arr[20]) {
	int left = 0, right = 19;
	
	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] == x) {
			return mid;
		}
		if (arr[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -100;
}

void printArr(int arr[20]) {
	cout << "Исходный массив: ";
	for (int i = 0; i < 20; i++) {
		cout << arr[i] << " ";
	}
}

void linSearch(int x, int arr[20]) {
	int k = 100;
	for (int i = 0; i < 20; i++) {
		if (arr[i] == x) {
			k = i;
			break;
		}
	}
	if (k != 100) {
		cout << "Элемент " << x << " находится под индексом " << k;
	}
	else {
		cout << "Данного элемента нет в массиве.";
	}
}

void sort(int arr[20]) {
	for (int i = 1; i < 20; i++) {
		for (int j = i; j > 0 && arr[j-1] > arr[j]; j--) {
			int r = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = r;
		}
	}
	for (int i = 0; i < 20; i++) {
		cout << arr[i] << " ";
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	const int n = 20;
	int x1, x2;
	int arr[n];

	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 101 - 50;
	}
	printArr(arr);
	cout << endl;
	cout << "Введите элемент для линейного поиска: "; cin >> x1;
	linSearch(x1, arr);
	cout << endl;
	cout << "Отсортированный вставками массив: ";
	sort(arr); cout << endl;
	cout << "Введите элемент для бинарного поиска: "; cin >> x2;
	if (binSearch(x2, arr) == -100) {
		cout << "Данного элемента нет в массиве";
	}
	else {
		cout<<"Результат: "<< binSearch(x2, arr);
	}
}