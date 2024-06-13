#include "Data.h"
using namespace std;

bool Date::isLeapYear() const
{
	return (year % 4 == 0 && year % 400 == 0 || year % 4 == 0 && year % 100 != 0);
}

int Date::monthDays() const
{
	switch (month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
	case 4: case 6: case 9: case 11:
		return 30;
	case 2:
		return isLeapYear() ? 29 : 28;
	}

	return 0;
}

void Date::nextDate()
{
	if (day == 31 && month == 12)
	{
		day = 1;
		month = 1;
		year++;
	}
	else if (day == monthDays())
	{
		day = 1;
		month++;
	}
	else
	{
		day++;
	}
}

void Date::prevDate()
{
	if (day == 1 && month == 1)
	{
		day = 31;
		month = 12;
		year--;
	}
	else if (day == 1)
	{
		month--;
		day = monthDays();
	}
	else
	{
		day--;
	}
}

//   Set&Get   //
Date::Date()
{
	struct tm* tim = new tm;
	time_t tt = time(NULL);
	localtime_s(tim, &tt);

	day = tim->tm_mday;
	month = tim->tm_mon + 1;
	year = tim->tm_year + 1900;
}

Date::Date(int year, int month, int day) : year(year), month(month), day(day)
{
}

void Date::setYear(int year)
{
	this->year = year;
}

int Date::getYear() const
{
	return year;
}

void Date::setMonth(int month)
{
	this->month = month;
}

int Date::getMonth() const
{
	return month;
}

void Date::setDay(int day)
{
	this->day = day;
}

int Date::getDay() const
{
	return day;
}

void Date::showDate() const
{
	cout << day / 10 << day % 10 << "." << month / 10 << month % 10 << "." << year << endl;

}



bool Date::valid() const
{
	if (day <= 0 || day > monthDays())
	{
		return false;
	}
	else if (month <= 0 || month > 12)
	{
		return false;
	}
	else
	{
		return true;
	}

	//Error chek
	cout << "ERROR" << endl;
	return false;
}

// Operators
bool Date::operator==(const Date& obj) const&
{

	return this->day == obj.day && this->month == obj.month && this->year == obj.year;
}

bool Date::operator!=(const Date& obj) const&
{

	//	return this->day != obj.day || this->month != obj.month || this->year != obj.year;
	return !(*this == obj);
}

bool Date::operator>(const Date& obj) const&
{
	if (this->year > obj.year)
	{
		return true;
	}
	else if (this->year == obj.year && this->month > obj.month)
	{
		return true;
	}
	else if (this->year == obj.year && this->month == obj.month && this->day > obj.day)
	{
		return true;
	}

	return false;
}

bool Date::operator<(const Date& obj) const&
{
	return !(*this > obj) && *this != obj;
}

bool Date::operator>=(const Date& obj) const&
{
	return (*this > obj) || *this == obj;
}

bool Date::operator<=(const Date& obj) const&
{
	return (*this < obj) || *this == obj;
}

Date& Date::operator+=(int days)
{
	for (int i = 0; i < days; i++)
	{
		this->nextDate();
	}
	return *this;
}

Date& Date::operator-=(int days)
{
	for (int i = 0; i < days; i++)
	{
		this->prevDate();
	}
	return *this;
}

Date& Date::operator+=(float month)
{
	this->month += month;
	if (this->month > 12)
	{
		year += (this->month - 1) / 12;
		this->month = (this->month - 1) % 12 + 1;
	}
	return *this;
}

Date& Date::operator-=(float month)
{
	this->month -= month;
	if (this->month <= 0) {

		year -= abs(12 - this->month) / 12;
		this->month = (12 + this->month - 1) % 12 + 1;

	}
	return *this;
}

Date& Date::operator+=(long years)
{
	this->year += years;
	return *this;
}

Date& Date::operator-=(long years)
{
	this->year -= years;
	return *this;
}


//+-
Date Date::operator+(int days) const&
{
	Date tmp = *this;
	tmp += days;
	return tmp;

}

Date Date::operator-(int days) const&
{
	Date tmp = *this;
	tmp -= days;
	return tmp;
}

Date Date::operator+(float months) const&
{
	Date tmp = *this;
	tmp += month;
	return tmp;
}

Date Date::operator-(float months) const&
{
	Date tmp = *this;
	tmp -= month;
	return tmp;
}

Date Date::operator+(long years) const&
{
	Date tmp = *this;
	tmp += year;
	return tmp;
}

Date Date::operator-(long years) const&
{
	Date tmp = *this;
	tmp -= year;
	return tmp;
}


// friends 
Date& Date::operator--()
{
	this->prevDate();
	return *this;
}

Date Date::operator--(int)
{
	Date tmp = *this;
	this->prevDate();
	return tmp;
}

Date& Date::operator++()
{
	this->nextDate();
	return *this;
}

Date Date::operator++(int)
{
	Date tmp = *this;
	this->nextDate();
	return tmp;
}




Date operator+(int days, const Date& a)
{
	return a + days;
}

Date operator-(int days, const Date& a)
{
	return a - days;
}

Date operator+(float months, const Date& a)
{
	return a + months;
}

Date operator-(float months, const Date& a)
{
	return a - months;
}

Date operator+(long years, const Date& a)
{
	return a + years;
}

Date operator-(long years, const Date& a)
{
	return a - years;
}

ostream& operator<<(ostream& os, const Date& t)
{
	os << t.day / 10 << t.day % 10 << "." << t.month / 10 << t.month % 10 << "." << t.year;
	return os;
}

istream& operator>>(istream& is, Date& t)
{
	do {
		cout << "dd mm yyyy:";
		is >> t.day >> t.month >> t.year;

	} while (!t.valid());
	return is;
}
