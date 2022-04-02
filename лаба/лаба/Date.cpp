#include "Date.h"
#include <iostream>

int CheckInt() 
{
	int digit;
	while (true) 
	{
		std::cin >> digit;
		if (std::cin.fail() || std::cin.get() != '\n') 
		{
			std::cout << "������������ ����, ����������, ������� �����>>";
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			continue;
		}
		return digit;
	}
}

Date& Date::operator++()
{
	std::cout << "��� ��������� �� 1?" << std::endl;
	std::cout << "1. ����" << std::endl;
	std::cout << "2. �����" << std::endl;
	std::cout << "3. ���" << std::endl;
	std::cout << ">>";
	int � = CheckInt();
	switch (�) 
	{
	case 1:
		this->day++;
		break;
	case 2:
		this->month++;
		break;
	case 3:
		this->year++;
		break;
	}
	this->CorDate(*this);
	return *this;
}

Date& Date::operator--()
{
	std::cout << "��� ��������� �� 1?" << std::endl;
	std::cout << "1. ����" << std::endl;
	std::cout << "2. �����" << std::endl;
	std::cout << "3. ���" << std::endl;
	std::cout << ">>";
	int � = CheckInt();
	switch (�) 
	{
	case 1:
		this->day--;
		break;
	case 2:
		this->month--;
		break;
	case 3:
		this->year--;
		break;
	}
	this->CorDate(*this);
	return *this;
}

Date::operator int() const
{
	int d,m,y;
	d = CheckInt();
	m = CheckInt();
	y = CheckInt();
	return Date(d,m,y);
}

int Date::GetDay()
{
	return this->day;
}

int Date::GetMonth()
{
	return this->month;
}

int Date::GetYear()
{
	return this->year;
}

void Date::SetDate()
{
	int x, y, z;
	std::cout << "������� ����:" << std::endl;
	std::cout << "�����>>";
	x = CheckInt();
	this->day = x;
	std::cout<< "\n";
	std::cout << "�����>>";
	y = CheckInt();
	this->month = y;
	std::cout << "\n";
	std::cout << "���>>";
	z = CheckInt();
	this->year = z;
	this->CorDate(*this);
}

void Date::CorDate(Date& val)
{	
	if (day < 1)
	{
		if ((month - 1) == 1 || (month - 1) == 3 || (month - 1) == 5 || (month - 1) == 7 || (month - 1) == 8 || (month - 1) == 10 || (month - 1) == 12) {
			day = 32 + (day - 2);
			month--;
			CorDate(val);
		}
		else if ((month - 1) == 4 || (month - 1) == 6 || (month - 1) == 9 || (month - 1) == 11) {
			day = 31 + (day - 2);
			month--;
			CorDate(val);
		}
		else if ((month - 1) == 2) {
			day = 28 + (day - 2);
			month--;
			CorDate(val);
		}
		else if (month == 0 || (month - 1) == 0) {
			day = 32 + (day - 1);
			month = 12;
			year--;
			CorDate(val);
		}
	}
	if (month < 1) {
		month = 12 + month;
		year--;
		CorDate(val);
	}
	if (year < 1)
	{
		std::cout << "�� ����� ������� ������, ���������� ��� � ��������� �����..." << std::endl;
		year = 2022;
		month = 3;
		day = 20;
		system("pause");
		return;
	}
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		if (day > 31) {
			month++;
			day = 1 + (day - 32);
			CorDate(val);
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30) {
			month++;
			day = 1 + (day - 31);
			CorDate(val);
		}
	}
	else if (month == 2) {
		if (day > 28){
			month++;
			day = 1 + (day - 29);
			CorDate(val);
		}
	}
	if (month > 12) {
		year++;
		month = 1 + (month - 13);
		CorDate(val);
	}
}

Date& operator++(Date& val, int n)
{
	std::cout << "��� �����������?" << std::endl;
	std::cout << "1. ����" << std::endl;
	std::cout << "2. �����" << std::endl;
	std::cout << "3. ���" << std::endl;
	std::cout << ">>";
	int � = CheckInt();
	std::cout << "�� ������� �����������?" << std::endl;
	std::cout << ">>";
	int x = CheckInt();
	switch (�)
	{
	case 1:
		val.day += x;
		break;
	case 2:
		val.month += x;
		break;
	case 3:
		val.year += x;
		break;
	default:
		std::cout << "�������� ������������ ����� ����.";
		system("pause");
		break;
	}
	val.CorDate(val);
	return val;
}

Date& operator--(Date& val, int n)
{
	std::cout << "��� ���������?" << std::endl;
	std::cout << "1. ����" << std::endl;
	std::cout << "2. �����" << std::endl;
	std::cout << "3. ���" << std::endl;
	std::cout << ">>";
	int � = CheckInt();
	std::cout << "�� ������� ���������?" << std::endl;
	std::cout << ">>";
	int x = CheckInt();
	switch (�) 
	{
	case 1:
		val.day -= x;
		break;
	case 2:
		val.month -= x;
		break;
	case 3:
		val.year -= x;
		break;
	default:
		std::cout << "�������� ������������ ����� ����." << std::endl;
		system("pause");
		break;
	}
	val.CorDate(val);
	return val;
}