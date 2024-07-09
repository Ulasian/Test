#include "field.h"
#include <iostream>

field::field(int pRowLength, int pColumnLength)
    : rowLength(pRowLength), columnLength(pColumnLength)
{
    array.resize(rowLength, std::vector<std::string>(columnLength, " "));
    createField();
}

void field::createField()
{
    for (int i = 0; i < rowLength; ++i)
    {
        for (int j = 0; j < columnLength; ++j)
        {
            array[i][j] = " ";
        }
    }
}

void field::printField()
{
    for (int i = 0; i < rowLength; ++i)
    {
        for (int j = 0; j < columnLength; ++j)
        {
            std::cout << array[i][j];
            if (j < columnLength - 1)
            {
                std::cout << "|";
            }
        }
        std::cout << std::endl;
        if (i < rowLength - 1)
        {
            for (int j = 0; j < columnLength; ++j)
            {
                std::cout << "-";
                if (j < columnLength - 1)
                {
                    std::cout << "+";
                }
            }
            std::cout << std::endl;
        }
    }
}

void field::arraySetValue(int pRow, int pColumn,std::string symbol)
{
    if (pRow >= 0 && pRow < rowLength && pColumn >= 0 && pColumn < columnLength)
    {
        array[pRow][pColumn] = symbol;
    }
    else
    {
        std::cerr << "Invalid position (" << pRow << ", " << pColumn << ")" << std::endl;
    }
}

std::string field::arrayGetValue(int pRow, int pColumn)
{
    if (pRow >= 0 && pRow < rowLength && pColumn >= 0 && pColumn < columnLength)
    {
        return array[pRow][pColumn];
    }
    else
    {
        std::cerr << "Invalid position (" << pRow << ", " << pColumn << ")" << std::endl;
        return "";
    }
}
