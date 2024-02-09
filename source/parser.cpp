/*
 * Copyright (C) 2024 Austin Choi
 * See end of file for extended copyright information
 */

// Include header files
#include <iostream>
#include "../header/parser.h"

// Preprocessor macro
#define Log(x) (std::cout << x << std::endl)

// Node method definitions
std::string Node::tokenLiteral()
{
    return token.literal;
}

// Statement method definitions

// Expression method definitions

// Identifier method definitions
void Identifier::expressionNode()
{
}

// LetStatement method definitions
void LetStatement::statementNode()
{
}

void LetStatement::expressionNode()
{
}

std::string LetStatement::tokenLiteral()
{
    return token.literal;
}

// Parser class method definitions
Parser::Parser(Lexer lexer) : lexer(lexer)
{
    this->nextToken();
    this->nextToken();
}

void Parser::nextToken()
{
    this->currentToken = this->peekToken;
    this->peekToken = this->lexer.getNextToken();
}

Program* Parser::parseProgram()
{
    return new Program();
}

Parser::~Parser()
{
    Log("Parser destroyed");
}


// Program method definitions
std::string Program::tokenLiteral()
{
    if(statements.size() > 0)
    {
        return statements[0].tokenLiteral();
    }
    else
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
