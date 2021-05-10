#pragma once
#include "Date.h"
#include "Common.h"
#include <iostream>
#include "Doctor.h"
using namespace std;

class Reception : public Common {
	Date date;
	int countPatients;
public:
	static int count;

	template<class X>
	friend void push_back(X*& m);
	friend ostream& operator<<(ostream& out, Reception& obj);

	Reception();
	~Reception();

	Date& getDate();

	void addPatient();
	void removeParient();
	void printAllReception();
	void makeAppoinment(Doctor* doc, Reception*& rec);

	int getCount();
	int getCountPatients();
	void setCountPatients(int countPatients);
	Reception& operator=(Reception& obj);
	Reception& operator=(Fio& obj);
	Reception& operator=(Date& obj);
};

