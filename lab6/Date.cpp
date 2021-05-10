#include "Date.h"

Date::Date()
{
    day = 0;
    month = 0;
    year = 0;
}

int Date::getDay()
{
    return this->day;
}

int Date::getMonth()
{
    return this->month;
}

int Date::getYear()
{
    return this->year;
}

void Date::setDay(int day)
{
    this->day = day;
}

void Date::setMonth(int month)
{
    this->month = month;
}

void Date::setYear(int year)
{
    this->year = year;
}

bool Date::operator==(Date& obj)
{
    if (this->getDay() == obj.getDay() &&
        this->getMonth() == obj.getMonth() &&
        this->getYear() == obj.getYear())
    {
        return true;
    }
    else
    {
        return false;
    }
}

istream& operator>>(istream& in, Date& obj)
{
    int year, month, day;
    bool check;

    // input year
    do {
        try {
            cout << "Введите год: ";
            cin >> year;
            if (!cin) throw 1; // if year not int
            else if (year < 0) throw 2; // if year is negative
            check = false;
        }
        catch (int err) {
            if (err == 1) {
                cerr << endl << "Поддерживаются только цифры! Повторите ввод..." << endl;
                cin.clear();
                cin.ignore(4096, '\n');
                check = true;
            }
            else if (err == 2) {
                cerr << endl << "Не может быть отрицательным!" << endl;
                check = true;
            }
        }
    } while (check);
    
    //input month
    do {
        try {
            cout << "Введите месяц (1-12): ";
            cin >> month;
            if (!cin) throw 1; // if month not int
            else if (month < 0) throw 2; // if month is negative
            else if (month < 1 || month > 12) throw 3; // if month not in range
            check = false;
        }
        catch (int err) {
            if (err == 1) {
                cerr << endl << "Поддерживаются только цифры! Повторите ввод..." << endl;
                cin.clear();
                cin.ignore(4096, '\n');
            }
            else if (err == 2) {
                cerr << endl << "Не может быть отрицательным!" << endl;
            }
            else if (err == 3)
            {
                cerr << endl << "Месяца указываются в диапазоне от 1 до 12!" << endl;
            }

            check = true;
        }
    } while (check);

    //input day
    do {
        try {
            cout << "Введите день: ";
            cin >> day;
            if (!cin) throw 1; // if day not int
            else if (day < 0) throw 2; // if day is negative
            else if (
                month == 1  ||
                month == 3  ||
                month == 5  ||
                month == 7  ||
                month == 8  ||
                month == 10 ||
                month == 12) 
            {
                if (day < 1 || day > 31) throw 3; // 31 days in month 
            }

            else if (
                month == 4 ||
                month == 6 ||
                month == 9 ||
                month == 11) 
            {
                if (day < 1 || day > 30) throw 4; // 30 days in month
            }

            else if (month == 2) {
                if (((400 - year % 400) / 400) || (((4 - year % 4) / 4) && (year % 100)))
                {
                    throw 5; // february in leap year
                }
                else {
                    throw 6; // february in not leap year
                }
            }

            check = false;
        }
        catch (int err) {
            if (err == 1) {
                cerr << endl << "Поддерживаются только цифры! Повторите ввод..." << endl;
                cin.clear();
                cin.ignore(4096, '\n');
            }
            else if (err == 2) {
                cerr << endl << "Не может быть отрицательным!" << endl;
            }
            else if (err == 3)
            {
                cerr << endl << "В этом месяце может быть только 31 день!" << endl;
            }
            else if (err == 4)
            {
                cerr << endl << "В этом месяце может быть только 30 дней!" << endl;
            }
            else if (err == 5)
            {
                cerr << endl << "В этом месяце может быть только 29 день!" << endl;
            }
            else if (err == 6)
            {
                cerr << endl << "В этом месяце может быть только 28 день!" << endl;
            }

            check = true;
        }
    } while (check);

    obj.setYear(year);
    obj.setMonth(month);
    obj.setDay(day);

    return in;
}

ostream& operator<<(ostream& out, Date& obj)
{
    out << obj.getDay() << "." << obj.getMonth() << "." << obj.getYear();
    return out;
}
