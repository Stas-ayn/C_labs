#include <iostream> //для организации ввода-вывода
#include <math.h> //для работы с математическими функциями
#include <locale.h>
using namespace std; //описание пространства имен std

int main() //заголовок главной функции
{
    setlocale(LC_ALL, "rus");
    double a, b, z1, z2; // описание переменных
    cout << "Введите a = "; // вывод сообщений на экран
    cin >> a;
    cout << "Введите b = ";
    cin >> b;

    // вычисляем значения переменных z1, z2
    z1 = (sin(a) + cos(2 * b - a)) / (cos(a) - sin(2 * b - a));
    z2 = (1 + sin(2 * b)) / cos(2 * b);

    cout << "z1 = " << z1 << "\nz2 = " << z2; // вывод результатов на экран
    return 0;
}
