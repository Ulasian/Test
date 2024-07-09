#include <iostream>
#include "field.h"
#include "player.h"
#include "rules.h"
#include "input.h"
using namespace std;
int rowLength;
int columnLength;
bool playing = true;
int row;
int column;
bool gameover = false;
bool validMove = false;
bool repeat = true;
int main()
{
    input myInput;
    do
    {
        std::cout << "Please enter an integer to create board: ";
        rowLength = myInput.getIntegerInput();
        columnLength = rowLength;
        field myfield(rowLength,columnLength);
        rules gameRules(rowLength,columnLength);
        player player1("X");
        player player2("O");
        myfield.printField();
        gameover = false;
        while (gameover == false)
        {
            do
            {
                cout << "Player 1 turn" << endl;
                cout << "Type Integer for row" << endl;
                row = myInput.getIntegerInput()-1;
                cout << "Type Integer for column" << endl;
                column = myInput.getIntegerInput()-1;
                validMove = player1.takeTurn(column,row,myfield);
            }while(!validMove);
            myfield.printField();
            std::cout << std::endl;
            gameRules.countTurns();
            if (gameRules.turnsLeft()==false||gameRules.gameWon(myfield, player1.getSymbol()) == true)
            {
                gameover = true;
            }
            else
            {
                do
                {
                    cout << "Player 2 turn" << endl;
                    cout << "Type Integer for row" << endl;
                    row = myInput.getIntegerInput()-1;
                    cout << "Type Integer for column" << endl;
                    column = myInput.getIntegerInput()-1;
                    validMove = player2.takeTurn(column,row,myfield);
                }while(!validMove);
                myfield.printField();
                std::cout << std::endl;
                gameRules.countTurns();
                if (gameRules.turnsLeft()==false||gameRules.gameWon(myfield, player2.getSymbol()) == true)
                {
                    gameover = true;
                }
            }
        }
        repeat = myInput.getYesOrNo();
    }while(repeat);
    return 0;
}
