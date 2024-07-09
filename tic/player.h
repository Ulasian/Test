#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "field.h"

class player {
public:
    player(std::string pSymbol);
    bool takeTurn(int row, int column, field& gameField);
    std::string getSymbol();

private:
    std::string symbol;
};

#endif // PLAYER_H
