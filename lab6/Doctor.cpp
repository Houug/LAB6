#define _CRT_SECURE_NO_WARNINGS

#include "Doctor.h"
#include "Fio.h"
#include "functions.h"
#include <string.h>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

Doctor::Doctor()
{
	this->count++;
	this->specialty = -1;
	this->qualification = -1;
}
Doctor::Doctor(char* surname, char* name, char* father, int spec, int qual)
{
	this->count++;
	this->getFIO().setFIO(surname, name, father);
	this->specialty = spec;
	this->qualification = qual;
}
Doctor::Doctor(Doctor& obj)
{
	this->count++;
	this->getFIO().setSurname(obj.getFIO().getSurname());
	this->getFIO().setName(obj.getFIO().getName());
	this->getFIO().setFather(obj.getFIO().getFather());
	this->specialty = obj.getSpecialtyId();
	this->qualification = obj.getQualificationId();
}
Doctor::~Doctor()
{
	count--;
}

int Doctor::getSpecialtyId()
{
	return this->specialty;
}
int Doctor::getQualificationId()
{
	return this->qualification;
}
int Doctor::getCount()
{
	return this->count;
}

void Doctor::setSpecialtyId(int spec)
{
	this->specialty = spec;
}

void Doctor::setQualificationId(int qual)
{
	this->qualification = qual;
}

void Doctor::addDoctor(Doctor*& m)
{
	push_back(m);
	int i = m->getCount() - 1;
	cin >> m[i];
}

//void Doctor::printDoctor(int n)
//{
//	char specialty[11], qualification[7];
//
//	switch (this[n].getSpecialtyId())
//	{
//	case 1:
//		strcpy(specialty, "Терапевт");
//		break;
//	case 2:
//		strcpy(specialty, "Кардиолог");
//		break;
//	case 3:
//		strcpy(specialty, "Стоматолог");
//		break;
//	default:
//		strcpy(specialty, "NAN");
//		break;
//	}
//	switch (this[n].getQualificationId())
//	{
//	case 0:
//		strcpy(qualification, "Высшая");
//		break;
//	case 1:
//		strcpy(qualification, "Первая");
//		break;
//	case 2:
//		strcpy(qualification, "Вторая");
//		break;
//	default:
//		strcpy(qualification, "NAN");
//		break;
//	}
//	
//	cout << setw(40) << this[n].getFIO() << setw(16) << specialty << setw(16) << qualification << endl;
//}
void Doctor::printAllDoctors()
{
	if (this->getCount())
	{
		printHeader();
		for (int i = 0; i < this->getCount(); i++)
		{
			cout << this[i];
		}
	}
	else
	{
		cerr << "База данных пустая!" << endl;
	}
}

void Doctor::standartObjectEvent(Doctor*& m)
{
	Doctor standardObject;

	cin >> standardObject;

	int stdcount = 0;

	for (int i = 0; i < this->count - 1; i++)
	{
		Fio obj = standardObject.getFIO();
		if (this[i] == obj &&
			this[i].specialty == standardObject.specialty &&
			this[i].qualification == standardObject.qualification)
		{
			stdcount++;
		}
	}
	if (stdcount != 0)
	{
		cout << endl << "Найдено эталонных объектов: " << stdcount << endl;
	}
	else
	{
		int size = this->getCount() - 1;
		push_back(m);
		m[size] = standardObject;
		
		cout << "Т.к. эталонный объект не был найден, он создался!" << endl;
	}
}

bool Doctor::operator==(Fio& obj)
{
	if (strcmp(this->getFIO().getSurname(), obj.getSurname()) == 0 &&
		strcmp(this->getFIO().getName(), obj.getName()) == 0 &&
		strcmp(this->getFIO().getFather(), obj.getFather()) == 0)
		return true;
	else return false;
}
Doctor& Doctor::operator=(Doctor& obj)
{
	this->getFIO().setSurname(obj.getFIO().getSurname());
	this->getFIO().setName(obj.getFIO().getName());
	this->getFIO().setFather(obj.getFIO().getFather());
	this->setQualificationId(obj.getQualificationId());
	this->setSpecialtyId(obj.getSpecialtyId());

	return *this;
}

bool Doctor::operator>(Doctor& obj)
{
	char bufMin[60], bufMax[60];

	strcpy(bufMin, obj.getFIO().getSurname());
	strcat(bufMin, " ");
	strcat(bufMin, obj.getFIO().getName());
	strcat(bufMin, " ");
	strcat(bufMin, obj.getFIO().getFather());

	strcpy(bufMax, this->getFIO().getSurname());
	strcat(bufMax, " ");
	strcat(bufMax, this->getFIO().getName());
	strcat(bufMax, " ");
	strcat(bufMax, this->getFIO().getFather());

	if (strcmp(bufMax, bufMin) > 0) {
		return true;
	}
	else return false;
}
bool Doctor::operator<(Doctor& obj)
{
	char bufMin[60], bufMax[60];

	strcpy(bufMin, obj.getFIO().getSurname());
	strcat(bufMin, " ");
	strcat(bufMin, obj.getFIO().getName());
	strcat(bufMin, " ");
	strcat(bufMin, obj.getFIO().getFather());

	strcpy(bufMax, this->getFIO().getSurname());
	strcat(bufMax, " ");
	strcat(bufMax, this->getFIO().getName());
	strcat(bufMax, " ");
	strcat(bufMax, this->getFIO().getFather());

	if (strcmp(bufMax, bufMin) < 0) {
		return true;
	}
	else return false;
}
