/*
 * Copyright (C) 2024 Austin Choi
 * See end of file for extended copyright information
 */

#include <iostream>
#include <vector>
#include "./lexer.h"

#pragma once

struct Node
{
    virtual std::string tokenLiteral();

    Token token;
    std::string value;
};

struct Statement : Node
{
    virtual void statementNode();
};

struct Expression : Node
{
    virtual void expressionNode();
};

struct Identifier : Expression
{
  void expressionNode();
};

struct LetStatement : Statement
{
    std::string tokenLiteral();
    void statementNode();
    void expressionNode();

    Token token;
    Identifier* name;
    Expression value;
};

struct Program : Node
{
    std::string tokenLiteral();
    std::vector<Statement> statements;
};

class Parser
{
public:
    Parser(Lexer);
    ~Parser();
    std::string tokenLiteral();
    void nextToken();
    Program* parseProgram();
    
private:
    Lexer lexer;
    Token currentToken;
    Token peekToken;

};

/*
 * Copyright (C) 2024 Austin Choi
 * 
 * interpreter
 * Following the writing an interpreter in go book and ThePrimeaVimeaTimeagen's videos
 *
 * This code is licensed under the GNU General Public License 3.0.
 * Please see the LICENSE file in the root directory of this project for the full license details.
 */
