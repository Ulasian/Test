#include "rules.h"

rules::rules(int pRowLength, int pColumnLength)
{
    rowLength=pRowLength;
    columnLength=pColumnLength;
    maxTurns=pRowLength * pColumnLength;
}

bool rules::gameWon(field gameField,std::string symbol)
{
    for (int i = 0; i < rowLength; ++i)
    {
        bool won = true;
        for (int j = 0; j < columnLength; ++j)
        {
            if (gameField.arrayGetValue(i, j) != symbol)
            {
                won = false;
                break;
            }
        }
        if (won)
        {
            return true;
        }
    }
    for (int j = 0; j < columnLength; ++j)
    {
        bool won = true;
        for (int i = 0; i < rowLength; ++i)
        {
            if (gameField.arrayGetValue(i, j) != symbol)
            {
                won = false;
                break;
            }
        }
        if (won)
        {
            return true;
        }
    }
    bool diagonal1 = true;
    bool diagonal2 = true;
    for (int i = 0; i < rowLength; ++i)
    {
        if (gameField.arrayGetValue(i, i) != symbol)
        {
            diagonal1 = false;
        }
        if (gameField.arrayGetValue(i, rowLength - 1 - i) != symbol)
        {
            diagonal2 = false;
        }
    }
    if (diagonal1 || diagonal2)
    {
        return true;
    }

    return false;
}

void rules::countTurns()
{
    maxTurns--;
}

bool rules::turnsLeft()
{
    if(maxTurns == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
