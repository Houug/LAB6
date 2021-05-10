#pragma once
#include <stdio.h>
#include "Doctor.h"
#include <fstream>
#include "Reception.h"

void loadData(Doctor*& m, Reception*& a, fstream& data, fstream& dataRec);
void createData(Doctor*& m);
void saveData(Doctor* m, Reception*& a, fstream& data, fstream& dataRec);