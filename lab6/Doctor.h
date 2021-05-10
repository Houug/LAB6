#pragma once
#include "Fio.h"
#include <iostream>
#include "Common.h"
#include <fstream>

using namespace std;

class Doctor : public Common {
	int specialty;
	int qualification;
public:
	static int count;

	friend Doctor findDoctor(Doctor* m);
	friend void filterDoctor(Doctor* oldArr, Doctor*& newArr, int& count);
	friend istream& operator>> (istream& in, Doctor& obj);
	friend ostream& operator<< (ostream& out, Doctor& obj);
	template<class X>
	friend void push_back(X*& m);

	Doctor();
	Doctor(char* surname, char* name, char* father, int spec, int qual);
	Doctor(Doctor& obj);
	~Doctor();
	
	int getSpecialtyId();
	int getQualificationId();
	int getCount();

	void setSpecialtyId(int spec);
	void setQualificationId(int qual);

	void addDoctor(Doctor*& m);
	void standartObjectEvent(Doctor*& m);
	void printAllDoctors();

	bool operator== (Fio& obj);
	bool operator> (Doctor& obj);
	bool operator< (Doctor& obj);
	Doctor& operator=(Doctor& obj);
};