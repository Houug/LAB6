#define _CRT_SECURE_NO_WARNINGS

#include "functions.h"
#include <cstring>
#include <iostream>
#include <iomanip>
#include "Doctor.h"
using namespace std;

void printHeader()
{
	cout << "\n========================================================================\n"
		 << setw(40) << "Ф.И.О Врача" << setw(16) << "Cпециальность" << setw(16) << "Квалификация"
		 << "\n========================================================================\n";
}
void printMenu()
{
	cout << "\n\n***************Меню**************\n"
		 << "1 - Добавить врача в базу\n2 - Поиск врача по Ф.И.О\n3 - Поиск врачей по специальности и квалификации\n"
		 << "4 - Сортировка базы по алфавиту\n5 - Вывод базы с врачами\n6 - Эталонный объект\n7 - Записаться к врачу\n8 - Посмотреть все записи\n"
		 << "9 - Выход из программы"
		 << "\n*********************************\n";
}
void printReception()
{
	cout << "\n======================================================================\n"
		<< setw(40) << "Ф.И.О Врача" << setw(12) << "Дата" << setw(18) << "Свободные записи"
		<< "\n======================================================================\n";
}
Doctor findDoctor(Doctor* m)
{
	int count = 0;
	Fio temp;

	cout << "Поиск врача по Ф.И.О\n";
	cin >> temp;

	Doctor foundDoctor(temp.getSurname(), temp.getName(), temp.getFather(), -1, -1);

	for (int i = 0; i < m->getCount() - 1; i++)
	{
		Fio fD = foundDoctor.getFIO();
		if (m[i] == fD)
		{
			count++;
			foundDoctor = m[i];
			break;
		}
	}
	if (count == 0) cerr <<  "Поиск не выдал результов\n";
	else
	{
		printHeader();
		cout << foundDoctor;
		return foundDoctor;
	}
}
void sortData(Doctor* m)
{
	int min;
	int size = m->getCount();
	Doctor temp;

	for (int i = 0; i < size; i++)
	{
		min = i;

		for (int j = i + 1; j < size; j++)
		{
			if (m[min] > m[j])
			{
				min = j;
			}
		}

		temp = m[i];
		m[i] = m[min];
		m[min] = temp;
	}
}

void filterDoctor(Doctor* oldArr, Doctor*& newArr, int& count)
{
	int spec = 0;
	int qual = 0;
	bool check;

	do {
		try {
			cout << "Введите специальность (1-3): ";
			cin >> spec;

			if (!cin) throw 0; // If spec not int
			else if (!(spec == 1 || spec == 2 || spec == 3)) throw 1; // If spec not 1,2 or 3

			check = false;
		}
		catch (int err) {
			if (err == 0) {
				cerr << endl << "Поддерживаются только цифры! Повторите ввод..." << endl;
				cin.clear();
				cin.ignore(4096, '\n');
			}
			else if (err == 1) {
				cerr << endl << "Поддерживаются только цифры 1,2 или 3." << endl;
			}

			check = true;
		}
	} while (check);

	do {
		try {
			cout << "Введите квалификация (0-2): ";
			cin >> qual;

			if (!cin) throw 0; // If qual not int
			else if (!(qual == 1 || qual == 2 || qual == 0)) throw 1; // If qual not 1,2 or 0

			check = false;
		}
		catch (int err) {
			if (err == 0) {
				cerr << endl << "Поддерживаются только цифры! Повторите ввод..." << endl;
				cin.clear();
				cin.ignore(4096, '\n');
			}
			else if (err == 1) {
				cerr << endl << "Поддерживаются только цифры 0,1 или 2." << endl;
			}

			check = true;
		}
	} while (check);

	for (int i = 0; i < oldArr->getCount(); i++)
	{
		if ((spec == oldArr[i].specialty) && (qual == oldArr[i].qualification))
		{
			Doctor* temp = new Doctor[count + 1];
			count++;
			for (int i = 0; i < count; i++)
			{
				temp[i] = oldArr[i];
			}

			delete[] newArr;
			newArr = temp;
		}
	}
	if (count == 0)
	{
		cout << "Поиск не выдал результов\n";
	}
}

istream& operator>>(istream& in, Doctor& obj)
{
	int spec, qual;
	bool check;

	cin >> obj.getFIO();

	do {
		try {
			cout << "Введите специальность (1-3): ";
			cin >> spec;

			if (!cin) throw 0; // If spec not int
			else if (!(spec == 1 || spec == 2 || spec == 3)) throw 1; // If spec not 1,2 or 3

			check = false;
		}
		catch (int err) {
			if (err == 0) {
				cerr << endl << "Поддерживаются только цифры! Повторите ввод..." << endl;
				cin.clear();
				cin.ignore(4096, '\n');
			}
			else if (err == 1) {
				cerr << endl << "Поддерживаются только цифры 1,2 или 3." << endl;
			}

			check = true;
		}
	} while (check);
	obj.setSpecialtyId(spec);

	do {
		try {
			cout << "Введите квалификация (0-2): ";
			cin >> qual;

			if (!cin) throw 0; // If qual not int
			else if (!(qual == 1 || qual == 2 || qual == 0)) throw 1; // If qual not 1,2 or 0

			check = false;
		}
		catch (int err) {
			if (err == 0) {
				cerr << endl << "Поддерживаются только цифры! Повторите ввод..." << endl;
				cin.clear();
				cin.ignore(4096, '\n');
			}
			else if (err == 1) {
				cerr << endl << "Поддерживаются только цифры 0,1 или 2." << endl;
			}

			check = true;
		}
	} while (check);
	obj.setQualificationId(qual);

	return in;
}
ostream& operator<<(ostream& out, Doctor& obj)
{
	char specialty[11], qualification[7];

	switch (obj.getSpecialtyId())
	{
	case 1:
		strcpy(specialty, "Терапевт");
		break;
	case 2:
		strcpy(specialty, "Кардиолог");
		break;
	case 3:
		strcpy(specialty, "Стоматолог");
		break;
	default:
		strcpy(specialty, "NAN");
		break;
	}
	switch (obj.getQualificationId())
	{
	case 0:
		strcpy(qualification, "Высшая");
		break;
	case 1:
		strcpy(qualification, "Первая");
		break;
	case 2:
		strcpy(qualification, "Вторая");
		break;
	default:
		strcpy(qualification, "NAN");
		break;
	}

	out << setw(40) << obj.getFIO() << setw(16) << specialty << setw(16) << qualification << endl;
	return out;
}
ostream& operator<<(ostream& out, Fio& obj)
{
	char buf[60];
	strcpy(buf, obj.getSurname());
	strcat(buf, " ");
	strcat(buf, obj.getName());
	strcat(buf, " ");
	strcat(buf, obj.getFather());

	out << buf;
	return out;
}
istream& operator>>(istream& in, Fio& obj)
{
	char buf[20];
	bool check;

	do {
		try {
			cout << "Введите фамилию: ";
			in.getline(buf, 20);

			for (int i = 0; i < strlen(buf); i++) {
				if (!isalpha(buf[i])) throw 1;
			}
			check = false;
		}
		catch (...) {
			cerr << endl << "Фамилия должна содержать только буквы!" << endl;
			check = true;
		}
	} while (check);
	obj.setSurname(buf);
	
	do {
		try {
			cout << "Введите имя: ";
			in.getline(buf, 20);

			for (int i = 0; i < strlen(buf); i++) {
				if (!isalpha(buf[i])) throw 1;
			}
			check = false;
		}
		catch (...) {
			cerr << endl << "Имя должно содержать только буквы!" << endl;
			check = true;
		}
	} while (check);
	obj.setName(buf);
	
	do {
		try {
			cout << "Введите отчество: ";
			in.getline(buf, 20);

			for (int i = 0; i < strlen(buf); i++) {
				if (!isalpha(buf[i])) throw 1;
			}
			check = false;
		}
		catch (...) {
			cerr << endl << "Имя должно содержать только буквы!" << endl;
			check = true;
		}
	} while (check);
	obj.setFather(buf);
}
