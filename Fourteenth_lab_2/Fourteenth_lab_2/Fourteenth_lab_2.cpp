#include <iostream>
#include <Windows.h>
#include <locale.h>
#include <string>
#include <iomanip>
using namespace std;

struct train {
	int number;
	string destination;
	int allPlaces[3];
	int freePlaces[3];
};

void menu() {
	cout << "МЕНЮ" << endl;
	cout << "1. Ввод данных" << endl;
	cout << "2. Просмотр данных о всех поездах" << endl;
	cout << "3. Поиск по пункту назначения и кол-ву плацкартных мест" << endl;
	cout << "4. Поиск по номеру поезда" << endl;
	cout << "5. Вызов меню" << endl;
	cout << "6. Выход" << endl << endl;
}

void input(train &exp) {
	cout << "Введите номер поезда: ";
	cin >> exp.number;
	cin.ignore(1000, '\n');
	cout << "Введите название пункта назначения рейса: ";
	getline(cin, exp.destination);
	cout << "Введите количество спальных, купейных и плацкартных мест через пробел: ";
	for (int i = 0; i < 3; i++) {
		cin >> exp.allPlaces[i]; //какого то хрена бесконечно зацикливается если попытаться ввести второй поезд
	}
	cout << "Введите количество свободных спальных, купейных и плацкартных мест через пробел: " << endl;
	for (int i = 0; i < 3; i++) {
		cin >> exp.freePlaces[i];
	}
}
void viewing(train exp) {
	cout << "Номер поезда: " << exp.number << endl;
	cout << "Пункт назначения рейса: " << exp.destination << endl;
	cout << setw(17) << right << "Спальных" << right << setw(14) << "Купейных" << right << setw(14) << "Плацкартных" << endl;
	cout << "Всего" << setw(9) << right << exp.allPlaces[0] << right << setw(14) << exp.allPlaces[1] << right << setw(13) << exp.allPlaces[2] << endl;
	cout << "Свободно" << setw(6) << exp.freePlaces[0] << right << setw(14) << exp.freePlaces[1] << right << setw(13) << exp.freePlaces[2] << endl << endl;
}

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);

	string dest;
	train exp;
	train listOfTrains[30];
	int act, plats, count = 0;
	menu();
	while (true) {

		cout << "Введите цифру необходимого действия: "; cin >> act;
		if (act > 6 || act < 1) {
			cout << "Такого действия нет!" << endl;
			continue;
			cin.clear(); cin.ignore(1000, '\n');
		}
		switch (act) {
			case 1: {
				input(listOfTrains[count]);
				count += 1;
				break;
			}
			case 2: {
				for (int i = 0; i < count; i++) {
					viewing(listOfTrains[i]);
				}
				break;
			}
			case 3:{
				bool k = true;
				cout << "Введите пункт назначения: ";
				cin >> dest;
				cout << "Введите необходимое количество плацкартных мест: ";
				cin >> plats;
				for (int i = 0; i < count; i++) {
					if (dest == listOfTrains[i].destination && plats <= listOfTrains[i].freePlaces[2]) {
						viewing(listOfTrains[i]);
						k = false;
					}
				}
				if (k) {
					cout << "Поезда с данными параметрами не существует" << endl;
				}
				break;
			}
			case 4: {
				bool k = true;
				int num;
				cout << "Введите номер поезда: ";
				cin >> num;
				for (int i = 0; i < count; i++) {
					if (num == listOfTrains[i].number) {
						viewing(listOfTrains[i]);
						k = false;
					}
				}
				if (k) {
					cout << "Поезда под данным номером не существует" << endl;
				}
				break;
			}
			case 5: {
				menu();
				break;
			}
		}
		if (act == 6) {
			break;
		}

	}

	return 0;
}