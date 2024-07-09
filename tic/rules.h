#ifndef RULES_H
#define RULES_H

#include "field.h"
#include <string>

class rules {
public:
    rules(int pRowLength, int pColumnLength);
    bool gameWon(field gameField,std::string symbol);
    void countTurns();
    bool turnsLeft();

private:
    int rowLength;
    int columnLength;
    int maxTurns;
};

#endif // RULES_H
