#ifndef SPREADSHEET_H
#define SPREADSHEET_H
#include "cell.h"

class Spreadsheet
{
public:
    Spreadsheet();
    Spreadsheet(int rc, int cc);
    ~Spreadsheet() = default;

public:
    bool operator!=(const Spreadsheet& other) const;
    int getRowCount() const;
    int getColumnCount() const;
    void setCellAt(int r, int c, const Cell& cl);
    void setCellAt(int r, int c, const std::string& st);
    Cell getCellAt(int r, int c);
    void addRow(int r);
    void removeRow(int r);
    void addColumn(int c);
    void removeColumn(int c);
    void swapRows(int r1, int r2);
    void swapColumns(int c1, int c2);
    void print();
    void init();
    
private:
    Cell** m_cells;
    int rowCount;
    int columnCount;
};


#endif  //SPREADSHEET_H