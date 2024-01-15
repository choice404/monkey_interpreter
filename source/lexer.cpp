/*
 * Copyright (C) 2024 Austin Choi
 * See end of file for extended copyright information
 */

// Include header files
#include <iostream>
#include "../header/lexer.h"

// Preprocessor macro
#define Log(x) (std::cout << x << std::endl)

Lexer::Lexer()
{
    Log("Lexer created");
}

Lexer::~Lexer()
{
    Log("Lexer destroyed");
}

Token Lexer::createToken(TokenType type, std::string literal)
{
    Token token;
    token.type = type;
    token.literal = literal;
    return token;
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
