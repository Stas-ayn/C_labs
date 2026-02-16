#include <iostream>
#include <locale.h>
#include <ctype.h>
#include <cstring>
#include <cstdlib>
using namespace std;

//int main()
//{
//    setlocale(LC_ALL, "rus");
//    char Arr1[25];
//    char Arr2[] = { "Second string!" };
//    char Arr3[] = { 'T','h','i','r','d',' ',
//                           's','t','r','i','n','g', '\0'};
//    const char* Arr4 = "Fourth string";
//    cout << "\nEnter string: \"First string\": ";
//    //cin >> Arr1; 
//    cin.getline(Arr1, 25);
//    cout << "\nString 1: " << Arr1; // Оператор 1
//    cout << "\nString 2: " << Arr2; // Оператор 2
//    cout << "\nString 3: " << Arr3; // Оператор 3
//    cout << "\nString 4: " << Arr4; // Оператор 4
//    return 0;
//}

int main() {
	setlocale(LC_ALL, "rus");
	char str[] = "2, 75.3, 24.45, 55, 0, 0.37";
	const char* ptr = str;                         //Оператор 1
	float Arr[10];
	int i = 0;
	printf("\nИсходная строка:\n%s\n", str);
	do {

		Arr[i] = atof(ptr);                    //Оператор 2
		i++;
		if (i > 9) break;

	} while ((ptr = strchr(ptr, ',')) && ++ptr);   //Оператор 3
	printf("\nМассив чисел : \n");
		for (int s = 0; s < i; s++)
			printf("%5.2f\n", Arr[s]);
	return 0;

}

