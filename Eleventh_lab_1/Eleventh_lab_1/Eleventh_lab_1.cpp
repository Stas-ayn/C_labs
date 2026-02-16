#include <iostream>
#include <locale.h>
using namespace std;

//void Swap(int a, int b);
//int main() {
//	int x, y;
//	cout << "\nEnter two numbers: ";
//	cin >> x >> y;
//	cout << "\nx=" << x << ", y=" << y << endl;
//	Swap(x, y);
//	cout << "\nx=" << x << ", y=" << y << endl;
//	return 0;
//
//}
//void Swap(int a, int b) {
//	int c;
//	c = a;
//	a = b;
//	b = c;
//	return;
//
//}



//void Swap(int* a, int* b);
//int main() {
//
//	int x, y;
//	cout << "\nEnter two numbers: ";
//	cin >> x >> y;
//	cout << "\nx=" << x << ", y=" << y << endl;
//	Swap(&x, &y);
//	cout << "\nx=" << x << ", y=" << y << endl;
//	return 0;
//
//}
//void Swap(int* a, int* b) {
//
//	int c;
//	c = *a;
//	*a = *b;
//	*b = c;
//	return;
//
//}



//void Swap(int& a, int& b);
//int main() {
//
//	int x, y;
//	cout << "\nEnter two numbers: ";
//	cin >> x >> y;
//	cout << "\nx=" << x << ", y=" << y;
//	Swap(x, y);
//	cout << "\nx=" << x << ", y=" << y << endl;
//	return 0;
//
//}
//void Swap(int& a, int& b) {
//
//	int c;
//	c = a;
//	a = b;
//	b = c;
//	return;
//
//}



//int* GetMem();
//int main() {
//
//	int* a = GetMem();
//	cout << "\n a is " << a;
//	cout << "\n*a is " << *a;
//	cout << endl;
//	return 0;
//
//}
//int* GetMem() {
//
//	int* c = new int(5);
//	return c;
//
//}



void  PrintData(int* s, int N);
void  PrintData(char* w);
int main() {

	int* a, n; char str[50];
	cout << "\nEnter the array size : "; cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++) a[i] = rand() % 101 - 50;
	PrintData(a, n);
	cout << "\nEnter a string : "; cin >> str;
	PrintData(str);
	return 0;

}

void  PrintData(int* s, int N) {

	cout << endl;
	for (int i = 0; i < N; i++) cout << s[i] << "  ";
	return;

}

void  PrintData(char* w) {

	cout << endl << w;
	return;

}