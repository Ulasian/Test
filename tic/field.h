#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include <string>

class field {
public:
    field(int pRowLength, int pColumnLength);
    void createField();
    void printField();
    void arraySetValue(int pRow, int pColumn,std::string symbol);
    std::string arrayGetValue(int pRow, int pColumn);

private:
    int rowLength;
    int columnLength;
    std::vector<std::vector<std::string>> array;
};

#endif // FIELD_H
