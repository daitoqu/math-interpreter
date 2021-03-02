// math-interpreter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "CLexer.h"
#include "CParser.h"

int main()
{
    std::string input;
    std::getline(std::cin, input);

    CLexer lexer(input);
    try {
        lexer.parseExpression();
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
        return 1;
    }

    auto tokens = lexer.getTokens();
    CParser parser(tokens);
    try {
        parser.parseTokens();
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
        return 2;
    }

    std::cout << parser.evaluateTree() << std::endl;

    return 0;
}