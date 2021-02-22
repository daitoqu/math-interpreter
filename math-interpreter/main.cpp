// math-interpreter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "CLexer.h"

int main()
{
    std::string input;
    std::getline(std::cin, input);

    CLexer lexer(input);
    lexer.parseExpression();

    return 0;
}