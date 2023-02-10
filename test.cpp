#include <iostream>
#include "cell.h"
#include "spreadsheet.h"
#include "date.h"

void testCellValues()
{
    std::cout << "The first test..." << std::endl;
    Cell c1;
    c1.setValue("19");

    if (c1.getValue() != "19")
    {
       std::cout << "Test failed! Problem: getValue()" << std::endl;
    }
    else 
    {
        std::cout << "Test passed!" << std::endl;
    }

    if (c1.toInt() != 19)
    {
        std::cout << "Test failed! Problem: toInt()" << std::endl;
    }
    else 
    {
        std::cout << "Test passed!" << std::endl;
    }

    Cell c2;
    c2.setValue("19.7");
    if (c2.toDouble() != 19.7)
    {
        std::cout << "Test failed! Problem: toDouble()" << std::endl;
    }
    else 
    {
        std::cout << "Test passed!" << std::endl;
    }
    
    Cell c3;       
    c3.setValue("99122003");
    Date dt((Month(12)), (Day(99)), (Year(2003)));
    if (c3.toDate() != dt)
    {
        std::cout << "Test failed! Problem: toDate()" << std::endl;
    }
    else 
    {
        std::cout << "Test passed!" << std::endl;
    }

    c3.reset();
    if (c3.getValue() != "")
    {
        std::cout << "Test failed! Problem: reset()" << std::endl;
    }
    else 
    {
        std::cout << "Test passed!" << std::endl;
    }
}

void testSpreadsheetValue()
{
    std::cout << "The second test..." << std::endl;
    Color r = Color::Red;
    Spreadsheet sp1(6, 7);
    Spreadsheet sp2(7, 8);

    Cell c1("30082003", r);
    sp1.setCellAt(3, 2, c1);
    if (sp1.getCellAt(3, 2) != c1)
    {
        std::cout << "Test failed! Problem: getCellAt()" << std::endl;
    }
    else 
    {
        std::cout << "Test passed!" << std::endl;
    }

    std::string st = "Hello";
    sp2.setCellAt(2, 3, st);
    if (sp2.getCellAt(2, 3).getValue() != st)
    {
        std::cout << "Test failed! Problem: setCellAt()" << std::endl;
    }
    else 
    {
        std::cout << "Test passed!" << std::endl;
    }


    sp1.addRow(4);
    if (sp1.getRowCount() != sp2.getRowCount())
    {
        std::cout << "Test failed! Problem: addRow()" << std::endl;
    }
    else 
    {
        std::cout << "Test passed!" << std::endl;
    }

    sp1.addColumn(2);
    if (sp1.getColumnCount() != sp2.getColumnCount())
    {
        std::cout << "Test failed! Problem: addColumn()" << std::endl;
    }
    else 
    {
        std::cout << "Test passed!" << std::endl;
    }

    Spreadsheet sp3(8, 9);
    sp3.removeRow(3);
    if (sp1.getRowCount() != sp3.getRowCount())
    {
        std::cout << "Test failed! Problem: removeRow()" << std::endl;
    }
    else 
    {
        std::cout << "Test passed!" << std::endl;
    }

    Spreadsheet sp4(7, 10); 
    sp4.removeColumn(5); 
    if (sp4.getColumnCount() != sp3.getColumnCount())
    {
        std::cout << "Test failed! Problem: removeColumn()" << std::endl;
    }
    else 
    {
        std::cout << "Test passed!" << std::endl;
    }

    sp4.setCellAt(3, 4, "C++");
    sp4.setCellAt(5, 4, "Pascal");
    sp4.swapRows(3, 5);
    if (sp4.getCellAt(3, 4).getValue() == "Pascal" && sp4.getCellAt(5, 4).getValue() == "C++")
    {
        std::cout << "Test passed!" << std::endl;
    }
    else 
    {
        std::cout << "Test failed! Problem: swapRows()" << std::endl;
    }

    sp4.setCellAt(1, 1, "Java");
    sp4.setCellAt(1, 6, "C");
    sp4.swapColumns(1, 6);
    if (sp4.getCellAt(1, 1).getValue() == "C" && sp4.getCellAt(1, 6).getValue() == "Java")
    {
        std::cout << "Test passed!" << std::endl;
    }
    else 
    {
        std::cout << "Test failed! Problem: swapColumns()" << std::endl;
    }
}
