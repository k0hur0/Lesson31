#pragma once
#include<iostream>
#include<ctime>

using namespace std;

class Date
{
	int year;
	int month;
	int day;

	bool isLeapYear()const;
	int monthDays()const;
	void nextDate();
	void prevDate();

public:
	Date();
	Date(int year, int month, int day);


	//===============================//
	void setYear(int year);
	int getYear()const;

	void setMonth(int month);
	int getMonth()const;

	void setDay(int day);
	int getDay()const;

	void showDate()const;

	bool valid()const;

	//   Operators    //
	bool operator == (const Date& obj)const&;
	bool operator != (const Date& obj)const&;
	bool operator > (const Date& obj)const&;
	bool operator < (const Date& obj)const&;
	bool operator >= (const Date& obj)const&;
	bool operator <= (const Date& obj)const&;

	//--------- ÎÏÅÐÀÒÎÐÈ ÏÐÈÑÂÎªÍÍß ---------	
	Date& operator += (int days); // äîäàòè days äí³â äî äàòè
	Date& operator -= (int days); // â³äíÿòè days äí³ â³ä äàòè
	Date& operator += (float months); // äîäàòè months ì³ñÿö³â äî äàòè
	Date& operator -= (float months); // â³äíÿòè months ì³ñÿö³ â³ä äàòè
	Date& operator += (long years); // äîäàòè years ðîê³â äî äàòè
	Date& operator -= (long years); // â³äíÿòè years ðîê³â â³ä äàòè

	//--------- ÀÐÈÔÌÅÒÈ×Í² ÎÏÅÐÀÒÎÐÈ ---------
	Date operator + (int days)const&;
	Date operator - (int days)const&;
	Date operator + (float months)const&;
	Date operator - (float months)const&;
	Date operator + (long years)const&;
	Date operator - (long years)const&;

	int operator - (const Date& obj)const&; // ê³ëüê³ñòü äí³â ì³æ äàòàìè

	// Friends
	Date& operator -- ();  // prefix
	Date operator -- (int);//postfix
	Date& operator ++ ();
	Date operator ++ (int);

	friend Date operator + (int days, const Date& a);
	friend Date operator - (int days, const Date& a);

	friend Date operator + (float months, const Date& a);
	friend Date operator - (float months, const Date& a);

	friend Date operator + (long years, const Date& a);
	friend Date operator - (long years, const Date& a);


	friend ostream& operator << (ostream& os, const Date& t);
	friend istream& operator >> (istream& is, Date& t);


};


