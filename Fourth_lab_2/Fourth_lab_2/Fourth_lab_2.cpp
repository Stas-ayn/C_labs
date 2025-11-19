#include <iostream>
#include <cmath>
#include <locale.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");

    const double eps = 1e-4;
    const double pi = 3.1415926535897932384626433832795;
    double x = pi / 2;
    short int n = 1;
    double S = 0;
    double T = (sin((2 * n - 1) * x) / (2 * n - 1));

    while (abs(T) > eps) {
        S += T;
        n += 1;
        T = (sin((2 * n - 1) * x) / (2 * n - 1));
    }

    cout << "\nИтоговая сумма: " << S << endl;
    cout << "Количество итераций: " << n - 1 << endl;


    return 0;
}
