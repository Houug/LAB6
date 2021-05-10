#define _CRT_SECURE_NO_WARNINGS
#include "Data.h"
#include "functions.h"
#include <iostream>
#include <fstream>
#include "Reception.h"

using namespace std;

void loadData(Doctor*& m, Reception*& a, fstream& data, fstream& dataRec)
{
	for (int i = 0; !data.eof(); i++)
	{
		char bufName[20], bufSurname[20], bufFather[20];
		int spec, qual;

		data >> bufSurname >> bufName >> bufFather >> spec >> qual;
		push_back(m);

		m[i].getFIO().setSurname(bufSurname);
		m[i].getFIO().setName(bufName);
		m[i].getFIO().setFather(bufFather);

		m[i].setSpecialtyId(spec);
		m[i].setQualificationId(qual);
	}
	dataRec.seekg(0, ios::end);
	if (dataRec.tellg())
	{
		dataRec.seekg(ios::beg);

		for (int i = 0; !dataRec.eof(); i++)
		{

			char bufName[20], bufSurname[20], bufFather[20];
			int day, month, year, countPatients;

			dataRec >> bufSurname >> bufName >> bufFather >> day >> month >> year >> countPatients;
			push_back(a);

			a[i].getFIO().setSurname(bufSurname);
			a[i].getFIO().setName(bufName);
			a[i].getFIO().setFather(bufFather);

			a[i].getDate().setDay(day);
			a[i].getDate().setMonth(month);
			a[i].getDate().setYear(year);
			a[i].setCountPatients(countPatients);
		}
	}
	
	cout << "Файлы успешно открыты!\n";
}
void createData(Doctor*& m)
{
	int n;
	bool check;

	do {
		try {
			cout << "Введите кол-во позиций в базе: ";
			cin >> n;

			if (!cin) throw 0; // If n not int

			check = false;
		}
		catch (int err) {
			if (err == 0) {
				cerr << endl << "Поддерживаются только цифры! Повторите ввод..." << endl;
				cin.clear();
				cin.ignore(4096, '\n');
			}

			check = true;
		}
	} while (check);

	for (int i = 0; i < n; i++)
	{
		cout << "\nВвод элемента базы номер %d:\n" << i + 1;
		m->addDoctor(m);
	}
}
void saveData(Doctor* m, Reception*& a, fstream& data, fstream& dataRec)
{
	data.seekg(ios_base::beg);

	data << m[0].getFIO().getSurname() << " "
		<< m[0].getFIO().getName() << " "
		<< m[0].getFIO().getFather() << " "
		<< m[0].getSpecialtyId() << " "
		<< m[0].getQualificationId();

	for (int i = 1; i < m->getCount(); i++)
	{
		data << endl 
			<< m[i].getFIO().getSurname() << " "
			<< m[i].getFIO().getName() << " "
			<< m[i].getFIO().getFather() << " "
			<< m[i].getSpecialtyId() << " "
			<< m[i].getQualificationId();
	}

	dataRec.seekg(ios_base::beg);

	dataRec << a[0].getFIO().getSurname() << " "
		<< a[0].getFIO().getName() << " "
		<< a[0].getFIO().getFather() << " "
		<< a[0].getDate().getDay() << " "
		<< a[0].getDate().getMonth() << " "
		<< a[0].getDate().getYear() << " "
		<< a[0].getCountPatients();

	for (int i = 1; i < a->getCount(); i++)
	{
		dataRec << endl
			<< a[i].getFIO().getSurname() << " "
			<< a[i].getFIO().getName() << " "
			<< a[i].getFIO().getFather() << " "
			<< a[i].getDate().getDay() << " "
			<< a[i].getDate().getMonth() << " "
			<< a[i].getDate().getYear() << " "
			<< a[i].getCountPatients();
	}
}