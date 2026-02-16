#include <iostream>
#include <locale.h>
#include <conio.h>
using namespace std;

void print(char);      // прототип функции

int main() {
    setlocale(LC_ALL, "rus");

    char x;
    cout << "\n¬водите символы." << "Enter Ц окончание ввода";
    do {
        x = getch();
        print(x);
    } while (x != 13);
    return 0;
}
void print(char a) { cout << a << "\t"; }
