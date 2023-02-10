#include <iostream>
#include "cell.h"
#include "date.h"

std::ostream& operator<<(std::ostream& os, const Cell& c)
{
    os << c.m_value;
    return os;
}

bool Cell::operator!=(const Cell& rhs) const
{
    return m_value != rhs.m_value || m_color != rhs.m_color;
}

Cell& Cell::operator=(const Cell& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    m_value = rhs.m_value;
    m_color = rhs.m_color;
    return *this;
}

Cell::Cell(const std::string& v, Color c)
{
    m_value = v;
    m_color = c;
}

void Cell::swap(Cell &lhs, Cell &rhs) {
    std::swap(lhs.m_value, rhs.m_value);
    std::swap(lhs.m_color, rhs.m_color);
}


void Cell::setValue(const std::string& v)
{
    m_value = v;
}

std::string Cell::getValue() const
{
    return m_value;
}

int Cell::toInt()
{
    int tmp = std::stoi(m_value);
    return tmp;
}

double Cell::toDouble()
{
    double tmp = std::stod(m_value);
    return tmp;
}
Date Cell::toDate()
{
    int tmp = std::stoi(m_value);
    int dd = tmp / 1000000;
    int mm = (tmp % 1000000) / 10000;
    int yy = tmp % 1000;
    Date date1(Month(mm), Day(dd), Year(yy + 2000));
    return date1;
}

void Cell::reset()
{
    m_value = "";
}

void Cell::setColor(Color c)
{
    m_color = c;
}

Color Cell::getColor() const
{
    return m_color;
}
