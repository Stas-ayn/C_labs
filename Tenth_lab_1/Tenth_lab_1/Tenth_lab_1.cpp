#include <iostream>
#include <locale.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int a = 7, b = 2;
    int* ptr = NULL;
    cout << "\na=" << a << ", &a=" << &a;
    cout << ", b=" << b << ", &b=" << &b;
    ptr = &a;
    cout << "\nДействие: ptr=&a. Результат: ptr=" << ptr << ", *ptr=" << *ptr;
    ptr = &b;
    cout << "\nДействие: ptr=&b. Результат: ptr=" << ptr << ", *ptr=" << *ptr;
    *ptr = 137;
    cout << "\nДействие: *ptr=137. Результат: b=" << b;
    ptr++;//или ptr+=2;
    *ptr = -105;
    cout << "\nДействие: ptr++, *ptr=-105. Результат: ptr="
        << ptr << ", *ptr=" << *ptr << endl;
    return 0;
}
