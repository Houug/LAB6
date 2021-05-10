#include "Reception.h"
#include <iostream>
#include <iomanip>
#include "functions.h"
using namespace std;

Reception::Reception()
{
	countPatients = 10;
	count++;
}

Reception::~Reception()
{
	count--;
}

Date& Reception::getDate()
{
	return date;
}

void Reception::addPatient()
{
	countPatients--;
}

void Reception::removeParient()
{
	countPatients++;
}

void Reception::printAllReception()
{
	if (this->count) {
		printReception();
		for (int i = 0; i < this->getCount(); i++)
		{
			cout << this[i];
		}
	}
	else {
		cout << endl << "Записей в базе нет!" << endl;
	}
	
}

void Reception::makeAppoinment(Doctor* doc, Reception*& rec)
{
	Fio tempFio;
	Date tempDate;

point:
	cin >> tempFio;
	for (int i = 0; i < doc->getCount(); i++) {
		if (doc[i] == tempFio) {

			break;
		}
		else {
			if (i != doc->getCount() - 2) {
				continue;
			}
			cerr << endl << "Врача с таким именем нет в базе! Повторите ввод..." << endl;
			goto point;
			/*ошибка из-за цикла!!*/
		}
	}

	cin >> tempDate;

	try {
		for (int i = 0; i < rec->count; i++) {
			if ((rec[i].getFIO() == tempFio) && (rec[i].getDate() == tempDate)) {
				if (rec->getCountPatients()) {
					throw i; // if doctor exist
				}
				else {
					throw -1; // if doctor exist but no appointment
				}
			}
		}
		throw -2; //if doctor not exist in database
	}
	catch (int ex) {
		if (ex == -1) {
			cerr << endl << "На введенную дату нет записи! Попробуйте записаться на другую дату..." << endl;
			goto point;
		}
		else if (ex == -2) {
			push_back(rec);
			rec[rec->getCount() - 1] = tempFio;
			rec[rec->getCount() - 1] = tempDate;
			rec[rec->getCount() - 1].addPatient();
		}
		else {
			rec[ex].addPatient();
			cout << endl << "Запись успешна!" << endl;
		}
	}
}

int Reception::getCount()
{
	return count;
}

int Reception::getCountPatients()
{
	return countPatients;
}

void Reception::setCountPatients(int countPatients)
{
	this->countPatients = countPatients;
}

Reception& Reception::operator=(Reception& obj)
{
	*this = obj.getFIO();
	*this = obj.getDate();
	this->setCountPatients(obj.getCountPatients());
	return *this;
}

Reception& Reception::operator=(Fio& obj)
{
	this->getFIO().setSurname(obj.getSurname());
	this->getFIO().setName(obj.getName());
	this->getFIO().setFather(obj.getFather());
	return *this;
}

Reception& Reception::operator=(Date& obj)
{
	this->getDate().setYear(obj.getYear());
	this->getDate().setMonth(obj.getMonth());
	this->getDate().setDay(obj.getDay());
	return *this;
}

ostream& operator<<(ostream& out, Reception& obj)
{
	out << setw(40) << obj.getFIO() << "  "
		<< obj.getDate() << " "
		<< setw(17) << obj.getCountPatients() << endl;
	return out;
}
