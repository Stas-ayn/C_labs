#include <iostream>
#include <locale.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int n=0;
	double num, sum = 0;
	double arr[30];
	cout << "¬ведите числа через пробел(введите 0 дл€ завершени€):";
	while (n < 30) {
		cin >> num;
		if (num == 0) {
			break;
		}
		arr[n] = num;
		sum += num;
		n++;
	}
	cout << "—умма чисел:"<<sum<<endl;
	cout << "Ёлементы, деленные на сумму: ";
	for (int i = 0; i < n; i++) {
		cout << (arr[i] / sum) << "\t";
	}

	return 0;
}

