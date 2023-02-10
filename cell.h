#ifndef CELL_H
#define CELL_H
#include "date.h"

enum class Color { 
    Red, 
    Black, 
    White };

class Cell
{
public:
    Cell() = default;
    Cell(const std::string& v, Color c);
    ~Cell() = default;

public: 
    bool operator!=(const Cell& rhs) const;
    Cell& operator=(const Cell& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Cell& c);
    void setColor(Color c);
    Color getColor() const;
    void setValue(const std::string& v);
    std::string getValue() const;
    int toInt();
    double toDouble();
    Date toDate();
    void reset();
    void swap(Cell &lhs, Cell &rhs);

private:
    std::string m_value;
    Color m_color;
};

#endif  //CELL_H