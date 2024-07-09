#include "input.h"
#include <iostream>
#include <limits>

input::input() {}

int input::getIntegerInput()
{
    int input;
    while (true)
    {
        std::cin >> input;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input please try again." << std::endl;
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return input;
        }
    }
}

bool input::getYesOrNo()
{
    int userInput;
    while (true)
    {
        std::cout << "Continue? Enter 1 for Yes or 0 for No: ";
        std::cin >> userInput;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter 1 or 0." << std::endl;
        }
        else if (userInput == 1 || userInput == 0)
        {
            return userInput == 1;
        }
        else
        {
            std::cout << "Invalid input. Please enter 1 or 0." << std::endl;
        }
    }
}
