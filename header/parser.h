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
  Token token;
  std::string value;
  std::string tokenLiteral();
  void expressionNode();
};

struct LetStatement : Statement
{
    Token token;
    Identifier* name;
    Expression value;
    std::string tokenLiteral();
    void statementNode();
    void expressionNode();
};

class Parser
{
public:
    Parser();
    ~Parser();
    std::string TokenLiteral();

private:
    std::vector<Statement> statements;

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
