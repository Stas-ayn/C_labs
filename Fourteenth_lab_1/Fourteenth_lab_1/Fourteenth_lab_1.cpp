#include <Windows.h>
#include <locale.h>
#include <iostream>>
#include <string>
#include <iomanip>

struct music {
	std::string name;
	std::string genre;
	std::string years;
	std::string fav_song;
};

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);

	music reGroups[10] = { {"Metallica", "Трэш-метал", "1981-Н.В.", "Master of Puppets"},
		{"Guns N'Roses", "Хард-рок", "1985 - Н.В.", "Sweet Child O'Mine"},
		{"Green Day", "Поп-панк", "1987-Н.В.", "Holiday"},
		{"Ария", "Хэви-метал", "1985-Н.В.", "Воля и Разум" },
		{"Radiohead", "Альт рок", "1985-Н.В.", "No Surprises"}
	};
	music groups[10];
	int i = 0;
	for (i; i < 10; i++) {
		std::string songs[3];
		std::cout << "Введите имя исполнителя или группы (введите break для завершения): "; 
		std::getline(std::cin, groups[i].name);
		if (groups[i].name == "break") {
			break;
		}
		std::cout << "Введите жанр: ";
		std::getline(std::cin, groups[i].genre);
		std::cout << "Введите годы функционирования: ";
		std::getline(std::cin, groups[i].years);
		std::cout << "Введите любимую песню: ";
		std::getline(std::cin, groups[i].fav_song);
	}
	std::cout << std::setw(12)<<"Название" << std::right << std::setw(12) << "Жанр" << std::right << std::setw(24) << "Годы существования" << std::right << std::setw(20) << "Любимые песни" << std::endl;
	//for (int j = 0; j < 5; j++) {
	//	std::cout << j + 1 << "." <<std::setw(10) << reGroups[j].name << std::setw(16) <<std::right<< reGroups[j].genre << std::setw(15)<< std::right << reGroups[j].years << std::right << std::setw(23) << reGroups[j].fav_song <<std::endl;
	//}
	for (int j = 0; j < i; j++) {
		std::cout << j + 1 << "." << std::setw(10) << groups[j].name << std::setw(16) << std::right << groups[j].genre << std::setw(15) << std::right << groups[j].years << std::right << std::setw(23) << groups[j].fav_song << std::endl;
	}
	return 0;
}