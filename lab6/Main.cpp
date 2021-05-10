#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <fstream>
#include "Doctor.h"
#include "Reception.h"
#include "functions.h"
#include "Data.h"

#define path "data.txt"
#define path2 "dataRec.txt"
using namespace std;

// Default count of Doctor's class objects
int Doctor::count = 0;
// Default count of Reception's class objects
int Reception::count = 0;

int main()
{
	setlocale(LC_ALL, "Russian");

	// Block of variables
	fstream data;
	fstream dataRec;
	Doctor* doctor = NULL;
	Doctor* foundDoctors = NULL;
	Reception* reception = NULL;
	int menu, count = 0;
	bool check;

	// Load/create database
	data.open(path);
	dataRec.open(path2);
	if (!data.is_open())
	{
		cout << "Файл не открылся!" << endl;
		data.open(path, fstream::app);
		if (data.is_open())
		{
			cout << "Создание нового файла!" << endl;
			createData(doctor);
		}
		else
		{
			cout << "Обратитесь к администратору!" << endl;
			return 0;
		}
	}
	else if(!dataRec.is_open()) {
		cout << "Файл не открылся!" << endl;
		dataRec.open(path2, fstream::app);
		if (dataRec.is_open())
		{
			cout << "Создание нового файла!" << endl;
		}
		else
		{
			cout << "Обратитесь к администратору!" << endl;
			return 0;
		}
	}
	else
	{
		loadData(doctor, reception, data, dataRec);
	}

	// Menu
	do
	{
		printMenu();
		do {
			try {
				cout << "Выберите пункт меню: ";
				cin >> menu;
				getchar();

				if (!cin) throw 0; // If menu not int

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

		switch (menu)
		{
		case 1:
			doctor->addDoctor(doctor);
			break;
		case 2:
			findDoctor(doctor);
			break;
		case 3:
			filterDoctor(doctor, foundDoctors, count);

			if (count != 0)
			{
				printHeader();
				for (int i = 0; i < count; i++)
				{
					cout << foundDoctors[i];
				}
			}
			delete[] foundDoctors;
			break;
		case 4:
			sortData(doctor);
			break;
		case 5:
			doctor->printAllDoctors();
			break;
		case 6:
			doctor->standartObjectEvent(doctor);
			break;
		case 7:
			reception->makeAppoinment(doctor, reception);
			break;
		case 8:
			reception->printAllReception();
			break;
		case 9:
			saveData(doctor, reception, data, dataRec);
			data.close();
			delete[] doctor;
			return 0;
		default:
			cout << "Введенный вами пункт меню не существует" << endl;
			break;
		}
	} while (TRUE);
}