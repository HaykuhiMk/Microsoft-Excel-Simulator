#include <iostream>
#include "date.h"

Day::Day(int d) : val(d) {}

Month::Month(int m) : val(m) {}

Year::Year(int y) : val(y) {}

Date::Date(const Month& m, const Day& d, const Year& y)
    : month(m.val), day(d.val), year(y.val) {}

void Date::print() const
{
    std::cout << day << "/" << month << "/" << year << std::endl;
}

bool Date::operator!=(const Date& rhs)
{
    return (this->getMonth() != rhs.getMonth() || this->getDay() != rhs.getDay() || this->getYear() != rhs.getYear());
}

int Date::getMonth() const
{
    return month;
}

int Date::getDay() const
{
    return day;
}

int Date::getYear() const
{
    return year;
}