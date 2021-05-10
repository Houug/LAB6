#define _CRT_SECURE_NO_WARNINGS
#include "Fio.h"
#include <cstring>

Fio::Fio()
{
	this->surname = new char[2];
	this->name = new char[2];
	this->father = new char[2];

	strcpy(this->surname, "S");
	strcpy(this->name, "N");
	strcpy(this->father, "F");
}
Fio::Fio(const Fio& obj)
{
	this->surname = new char[strlen(obj.surname) + 1];
	this->name = new char[strlen(obj.name) + 1];
	this->father = new char[strlen(obj.father) + 1];

	strcpy(this->surname, obj.surname);
	strcpy(this->name, obj.name);
	strcpy(this->father, obj.father);
}
Fio::~Fio()
{
	delete[] this->surname;
	delete[] this->name;
	delete[] this->father;
}

char* Fio::getSurname() { return this->surname; }
char* Fio::getName() { return this->name; }
char* Fio::getFather() { return this->father; }

void Fio::setSurname(char* surname) {
	delete[] this->surname;
	this->surname = new char[strlen(surname) + 1];
	strcpy(this->surname, surname);
}
void Fio::setName(char* name) {
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
void Fio::setFather(char* father) {
	delete[] this->father;
	this->father = new char[strlen(father) + 1];
	strcpy(this->father, father);
}

void Fio::setFIO(char* surname, char* name, char* father)
{
	this->surname = new char[strlen(surname) + 1];
	this->name = new char[strlen(name) + 1];
	this->father = new char[strlen(father) + 1];
	strcpy(this->surname, surname);
	strcpy(this->name, name);
	strcpy(this->father, father);
}

bool Fio::operator==(Fio& obj)
{
	if (strcmp(this->getSurname(), obj.getSurname()) == 0 &&
		strcmp(this->getName(), obj.getName()) == 0 &&
		strcmp(this->getFather(), obj.getFather()) == 0)
		return true;
	else return false;
}
