#include <iostream>
#include <string>
using namespace std;


class Date
{
	friend ostream& operator<<(ostream& o,  Date & d)
	{
		if (d.month < 1 || d.month > 12)
			d.month = 1;
		if (d.day < 1 || d.day >30)
			d.day = 1;
		if (d.year < 0)
			d.year = 2000;
		o << d.monthNames[d.month-1] << " " << d.day << ", " << d.year << endl;
		return o;
	}
	friend istream& operator>>(istream& i, Date & d)
	{
		cout << "Enter Day : " << endl;
		i >> d.day;
		cout << "Enter Month : " << endl;
		i >> d.month;
		cout << "Enter Year : " << endl;
		i >> d.year;
		return i;
	}
	friend bool check(Date & d);
private:
	const string monthNames[13] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	int month;
	int day;
	int year;

public:
	Date();
	Date(int month, int day, int year);
	bool operator==(Date & d);
	Date operator+(int  d);
	const Date& operator=(const Date& d);
	Date operator++();
	Date operator++(int i);
	Date operator--();
	Date operator--(int i);
	int operator[](int i);
};

Date::Date()
{
	this->month = 1;
	day = 1;
	year = 2000;
}

Date::Date(int month, int day, int year)
{
	if (month < 1 || month >> 12)
		month = 1;
	else	
		this->month = month;
	
	if (day < 1 || day >30)
		day = 1;
	else
		this->day = day;
	if (year < 0)
		year = 2000;
	else
		this->year = year;
}

bool Date::operator==(Date & d)
{
	if (this->month == d.month && this->day == d.day && this->year == d.year)
		return true;
	return false;
}

Date Date::operator+(int d)
{
	Date temp;
	int ydivisor = d/360;						//counts if any year is added
	int yrem = d % 360;						//days after addition of years
	if (ydivisor > 0)
		year = year + ydivisor;	
	ydivisor = yrem;								//updtaes it for next use
	int mdivisor = ydivisor / 30;			//checks how many months added
	int mrem = mdivisor % 30;				//days after addition of months
	if (mdivisor > 0)
		month = month + mdivisor;	
	if (mrem > 0)
		day = day + mrem;
	temp.day = this->day;
	temp.month = this->month;
	temp.year = this->year;
	return temp;
}

const Date& Date::operator=(const Date& d)
{
	this->day = d.day;
	this->month = d.month;
	this->year = d.year;
	return *this;
}

Date Date::operator--()
{
	this->day--;
	return *this;
}
Date Date::operator--(int i)
{
	Date temp = *this;
	this->day--;
	return temp;
}

Date Date::operator++()
{
	this->day++;
	return *this;
}
Date Date::operator++(int i)
{
	Date temp = *this;
	this->day++;
	return temp;
}

int Date::operator[](int i)
{
	if (i == 0)
		return day;
	else if (i == 1)
		return month;
	else if (i == 2)
		return year;
	else
	{
		cout << "it should be 0,1, or 2" << endl;
		return day;
	}
}


