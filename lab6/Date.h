#pragma once
#include <iostream>
using namespace std;
class Date {
	int day;
	int month;
	int year;
public:
	Date();

	friend istream& operator>>(istream& in, Date& obj);
	friend ostream& operator<<(ostream& out, Date& obj);
	
	int getDay();
	int getMonth();
	int getYear();

	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);

	bool operator==(Date& obj);
};

