#include <iostream>
#include <Windows.h>
#include <locale.h>
#include <string>
#include <fstream>
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



void inputing(train& exp, ofstream& output) {
	cout << "Введите номер поезда: ";
	cin >> exp.number;
	output << exp.number << " ";
	cin.ignore(1000, '\n');
	cout << "Введите название пункта назначения рейса: ";
	getline(cin, exp.destination);
	output << exp.destination << " ";
	cout << "Введите количество спальных, купейных и плацкартных мест через пробел: ";
	for (int i = 0; i < 3; i++) {
		cin >> exp.allPlaces[i]; 
		output << exp.allPlaces[i] << " ";
	}
	cout << "Введите количество свободных спальных, купейных и плацкартных мест через пробел: " << endl;
	for (int i = 0; i < 3; i++) {
		cin >> exp.freePlaces[i];
		output << exp.freePlaces[i] << " ";
	}
	output << endl;
}
void viewing(ifstream& input, int n) {
	input.seekg(0, ios::beg);
	train tran;
	bool k = true;
	if (n == -1){
		while (input >> tran.number) {
			cout << "Номер поезда: " << tran.number << endl;
			input >> tran.destination;
			cout << "Пункт назначения рейса: " << tran.destination << endl;
			cout << setw(17) << right << "Спальных" << right << setw(14) << "Купейных" << right << setw(14) << "Плацкартных" << endl;
			for (int i = 0; i < 3; i++) { input >> tran.allPlaces[i]; }
			for (int i = 0; i < 3; i++) { input >> tran.freePlaces[i]; }
			cout << "Всего" << setw(9) << right << tran.allPlaces[0] << right << setw(14) << tran.allPlaces[1] << right << setw(13) << tran.allPlaces[2] << endl;
			cout << "Свободно" << setw(6) << tran.freePlaces[0] << right << setw(14) << tran.freePlaces[1] << right << setw(13) << tran.freePlaces[2] << endl << endl;
		}
	}
	if (n == 1) {
		int num1;
		cout << "Введите номер поезда: ";
		cin >> num1;
		while (input >> tran.number) {
			input >> tran.destination;
			for (int i = 0; i < 3; i++) { input >> tran.allPlaces[i]; }
			for (int i = 0; i < 3; i++) { input >> tran.freePlaces[i]; }
			if (num1 == tran.number) {
				cout << "Номер поезда: " << tran.number << endl;
				cout << "Пункт назначения рейса: " << tran.destination << endl;
				cout << setw(17) << right << "Спальных" << right << setw(14) << "Купейных" << right << setw(14) << "Плацкартных" << endl;
				cout << "Всего" << setw(9) << right << tran.allPlaces[0] << right << setw(14) << tran.allPlaces[1] << right << setw(13) << tran.allPlaces[2] << endl;
				cout << "Свободно" << setw(6) << tran.freePlaces[0] << right << setw(14) << tran.freePlaces[1] << right << setw(13) << tran.freePlaces[2] << endl << endl;
				k = false;
			}
		}
		if(k) cout << "Поезда с данными параметрами не существует" << endl;
	}
	if (n == 0) {
		int num0;
		string dest;
		cout << "Введите пункт назначения: "; cin >> dest;
		cout << "Ввдедите количество необходимых плацкартных мест: "; cin >> num0;
		while (input >> tran.number) {
			input >> tran.destination;
			for (int i = 0; i < 3; i++) { input >> tran.allPlaces[i]; }
			for (int i = 0; i < 3; i++) { input >> tran.freePlaces[i]; }
			if (tran.destination == dest && tran.freePlaces[2] >= num0) {
				cout << "Номер поезда: " << tran.number << endl;
				cout << "Пункт назначения рейса: " << tran.destination << endl;
				cout << setw(17) << right << "Спальных" << right << setw(14) << "Купейных" << right << setw(14) << "Плацкартных" << endl;
				cout << "Всего" << setw(9) << right << tran.allPlaces[0] << right << setw(14) << tran.allPlaces[1] << right << setw(13) << tran.allPlaces[2] << endl;
				cout << "Свободно" << setw(6) << tran.freePlaces[0] << right << setw(14) << tran.freePlaces[1] << right << setw(13) << tran.freePlaces[2] << endl << endl;
				k = false;
			}
		}
		if (k) cout << "Поезда с данными параметрами не существует" << endl;
	}
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
			cin.clear(); cin.ignore(1000, '\n');
			continue;
		}
		switch (act) {
		case 1: {
			ofstream output("storage.txt", ios::app);
			inputing(listOfTrains[count], output);
			count += 1;
			output.close();
			break;
		}
		case 2: {
			int n = -1;
			ifstream input("storage.txt", ios::in);
			viewing(input, -1);
			input.close();
			break;
		}
		case 3: {
			ifstream input("storage.txt", ios::in);
			viewing(input, 0);
			input.close();
			break;
		}
		case 4: {
			ifstream input("storage.txt", ios::in);
			viewing(input, 1);
			input.close();
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