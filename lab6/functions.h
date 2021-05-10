#pragma once
#include "Doctor.h"
#include "Reception.h"

void printHeader();
void printMenu();
void printReception();
Doctor findDoctor(Doctor* m);
void sortData(Doctor* m);

template<class X>
void push_back(X*& m)
{
	int size = m->count;
	X* temp = new X[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = m[i];
	}

	delete[] m;
	m = temp;
}