/*
 * Copyright (C) 2024 Austin Choi
 * See end of file for extended copyright information
 */

// Include header files
#include <iostream>
#include "../header/parser.h"

// Preprocessor macro
#define Log(x) (std::cout << x << std::endl)

// Identifier class method definitions
std::string Identifier::tokenLiteral()
{
    return token.literal;
}

void Identifier::expressionNode() {}

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

// Program class method definitions
std::string Program::tokenLiteral()
{
    if (statements.size() > 0)
    {
        return statements[0].tokenLiteral();
    }
    else
    {
        return "";
    }
}

// Parser class method definitions
Parser::Parser(Lexer* lexer)
{
    this->nextToken();
    this->nextToken();
}

void Parser::nextToken()
{
    currentToken = peekToken;
    peekToken = lexer->getNextToken();
}

Parser::~Parser() {}

Program* Parser::parseProgram()
{
    return nullptr;
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
