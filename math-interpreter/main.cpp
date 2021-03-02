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
    lexer.parseExpression();
    auto tokens = lexer.getTokens();

    CParser parser(tokens);
    parser.parse();

    double a = parser.getTree()->Evaluate();

    return 0;
}