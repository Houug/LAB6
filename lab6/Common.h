#pragma once
#include "Fio.h"
class Common {
	Fio fio;
public:
	Fio& getFIO();

	virtual int getCount() = 0;
};