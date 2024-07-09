#include "player.h"
#include <string>
#include <iostream>

player::player(std::string pSymbol)
{
    symbol=pSymbol;
}

bool player::takeTurn(int row, int column, field& gameField)
{
    if (gameField.arrayGetValue(row, column) == " ")
    {
        gameField.arraySetValue(row, column, symbol);
        return true;
    }
    std::cout << "spot taken" << std::endl;
    return false;
}

std::string player::getSymbol()
{
    return symbol;
}
