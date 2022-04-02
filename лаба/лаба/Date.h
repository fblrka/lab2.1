#pragma once
class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date() 
	{
		day = 1;
		month = 1;
		year = 1;
	}
	Date(int day, int month, int year) 
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}

	int GetDay();
	int GetMonth();
	int GetYear();

	void SetDate();

	void CorDate(Date& val);

	Date& operator ++();
	Date& operator --();

	friend Date& operator ++(Date& val, int n);
	friend Date& operator --(Date& val, int n);

	operator int() const;

};