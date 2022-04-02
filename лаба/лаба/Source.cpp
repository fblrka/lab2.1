#include <iostream>
#include <Windows.h>
#include <string>
#include "Date.h"

int IsInt() {
	int digit;
	while (true) {
		std::cin >> digit;
		if (std::cin.fail() || std::cin.get() != '\n') {
			std::cout << "Некорректный ввод, пожалуйста, введите снова>>";
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			continue;
		}
		return digit;
	}
}

void PrintDate(Date& date) {
	if ((date.GetDay() > 9) && (date.GetMonth() > 9)) {
		std::cout << "Текущая дата: " + std::to_string(date.GetDay()) + '.' + std::to_string(date.GetMonth())
			+ '.' + std::to_string(date.GetYear()) << std::endl;
	}
	else if ((date.GetDay() < 10) && (date.GetMonth() > 9)) {
		std::cout << "Текущая дата: 0" + std::to_string(date.GetDay()) + '.' + std::to_string(date.GetMonth())
			+ '.' + std::to_string(date.GetYear()) << std::endl;
	}
	else if ((date.GetDay() > 9) && (date.GetMonth() < 10)) {
		std::cout << "Текущая дата: " + std::to_string(date.GetDay()) + ".0" + std::to_string(date.GetMonth())
			+ '.' + std::to_string(date.GetYear()) << std::endl;
	}
	else if ((date.GetDay() < 10) && (date.GetMonth() < 10)) {
		std::cout << "Текущая дата: 0" + std::to_string(date.GetDay()) + ".0" + std::to_string(date.GetMonth())
			+ '.' + std::to_string(date.GetYear()) << std::endl;
	}
}

int main() {

	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Date date;
	date.SetDate();

	int x = 1, c, a;
	while (x) {
		system("cls");
		std::cout << "Главное меню" << std::endl;
		PrintDate(date);
		std::cout << "1. Установить текущую дату" << std::endl;
		std::cout << "2. Увеличить дату" << std::endl;
		std::cout << "3. Уменьшить дату" << std::endl;
		std::cout << "0. Завершить работу программы" << std::endl;
		std::cout << "Введите пункт меню>>";
		c = IsInt();
		switch (c) {
		case 1:
			std::cout << "\n";
			date.SetDate();
			break;
		case 2:
			std::cout << "1. Инкрементировать на 1" << std::endl;
			std::cout << "2. Инкрементировать на пользовательское число" << std::endl;
			std::cout << ">>";
			a = IsInt();
			switch (a) {
			case 1:
				++date;
				break;
			case 2:
				date++;
				break;
			default:
				std::cout << "Введите существующий пункт меню." << std::endl;
				system("pause");
			}
			break;
		case 3:
			std::cout << "1. Декрементировать на 1" << std::endl;
			std::cout << "2. Декрементировать на пользовательское число" << std::endl;
			std::cout << ">>";
			a = IsInt();
			switch (a) {
			case 1:
				--date;
				break;
			case 2:
				date--;
				break;
			default:
				std::cout << "Введите существующий пункт меню." << std::endl;
				system("pause");
			}
			break;
		case 0:
			exit(0);
			break;
		default:
			std::cout << "Введите существующий пункт меню." << std::endl;
			system("pause");
			break;
		}
	}
	return 0;
 }