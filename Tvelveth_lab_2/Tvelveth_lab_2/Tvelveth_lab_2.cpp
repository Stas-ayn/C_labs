#include <iostream>
#include <locale.h>
#include <ctype.h>
#include <cstdlib>
#include <Windows.h>
#include <cstring>
using namespace std;

bool puncCheck(char st) {
	const char* punctuations = ".,!?:;() ";
	for (int i = 0; i < strlen(punctuations); i++) {
		if (st == punctuations[i]) {
			return true;
		}
	}
	return false;
}

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);

	char str[200] = {}; //инициализирую нулями
	cout << "Введите текст: ";
	cin.getline(str, 200);
	int ssize = strlen(str);
	int countA = 0;
	int count = 0;

	for (int i = 0; i < ssize; i++) { // использую ssize чтоб не выйти за пределы массива
		if (str[i+1] == '\0' || puncCheck(str[i+1])) {
			count += 1;
			if (str[i] == 'а') {
				countA += 1;
			}
		}
	}
	double procent = (1.0 * countA / count) * 100;

	//cout << str<< endl;
	cout <<"Размер текста: "<< ssize << endl;
	cout <<"Общее количество слов: " << count << endl;
	cout <<"Количество слов, заканчивающихся на 'а' в тексте: "<< countA << endl;
	cout << "Процент слов, оканчивающихся на букву 'а': " << procent << '%';

	return 0;
}