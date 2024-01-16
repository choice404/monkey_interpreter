/*
 * Copyright (C) 2024 Austin Choi
 * See end of file for extended copyright information
 */

// Include header files
#include <iostream>
#include "../header/parser.h"

// Preprocessor macro
#define Log(x) (std::cout << x << std::endl)

// Node class method definitions

// Statement class method definitions

// Expression class method definitions

// Identifier class method definitions
std::string Identifier::tokenLiteral()
{
    return token.literal;
}

void Identifier::expressionNode()
{
    Log("Identifier expressionNode function");
}

// LetStatement class method definitions
void LetStatement::statementNode()
{
    Log("LetStatement statementNode function");
}

void LetStatement::expressionNode()
{
    Log("LetStatement expressionNode function");
}

std::string LetStatement::tokenLiteral()
{
    return token.literal;
}

// Parser class method definitions
Parser::Parser()
{
    Log("Parser created");
}

Parser::~Parser()
{
    Log("Parser destroyed");
}

std::string Parser::TokenLiteral()
{
    if(statements.size() > 0)
    {
        return statements[0].TokenLiteral();
    } else
    {
        return "";
    }
}

/*
 * Copyright (C) 2024 Austin Choi
 * 
 * interpreter
 * Following the writing an interpreter in go book and ThePrimeaVimeaTimeagen's videos
 *
 * This code is licensed under the GNU General Public License 3.0.
 * Please see the LICENSE file in the root directory of this project for the full license details.
 */
