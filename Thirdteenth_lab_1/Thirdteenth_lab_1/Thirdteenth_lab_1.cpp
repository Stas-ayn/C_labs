#include <iostream>
#include <locale.h>
#include <string>
#include <Windows.h>
using namespace std;

bool puncCheck(char st) {
	string punctuations = ".,!?:;() ";
	return punctuations.find(st) != string::npos;
}

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);

	string text;
	string r = "";
	cout << "Введите текст: ";
	getline(cin, text);
	text += ',';
	int ssize = text.size();

	for (int i = 0; i < ssize; i++) {
		if (puncCheck(text[i])) {
			if (not r.empty()) {
				cout << "Слово: " << r << ";  " << "Количество букв: " << size(r) << endl;
				r.clear();
			}
		}
		else {
			r += text[i];
		}
	}
	return 0;
}