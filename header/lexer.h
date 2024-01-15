/*
 * Copyright (C) 2024 Austin Choi
 * See end of file for extended copyright information
 */

#pragma once

#include <iostream>

/* class TokenType */
/* { */
/* public: */
/*     std::string ILLEGAL = "ILLEGAL"; */
/*     std::string ENDOFFILE = "EOF"; */

/*     // Identifiers + literals */
/*     std::string IDENT = "IDENT"; // add, foobar, x, y, ... */
/*     std::string INT = "INT"; // 123456789 */

/*     // Operators */
/*     std::string ASSIGN = "="; // = */
/*     std::string PLUS = "+"; // + */
                
/*     // Delimiters */
/*     std::string COMMA = ","; // , */
/*     std::string SEMICOLON = ";"; // ; */

/*     std::string LPAREN = "("; // ( */
/*     std::string RPAREN = ")"; // ) */
/*     std::string LBRACE = "{"; // { */
/*     std::string RBRACE = "}"; // } */

/*     // Keywords */
/*     std::string FUNCTION = "FUNCTION"; // fn */
/*     std::string LET = "LET"; // let */
/* }; */

enum TokenType
{
    ILLEGAL,
    ENDOFFILE,
    IDENT,
    INT,
    ASSIGN,
    PLUS,
    COMMA,
    SEMICOLON,
    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,
    FUNCTION,
    LET,
};

const char* TokenTypeString[] = {
    "ILLEGAL",
    "EOF",
    "IDENT",
    "INT",
    "ASSIGN",
    "PLUS",
    "COMMA",
    "SEMICOLON",
    "LPAREN",
    "RPAREN",
    "LBRACE",
    "RBRACE",
    "FUNCTION",
    "LET",
};

struct Token
{
    std::string type;
    std::string literal;
};

class Lexer
{
public:
    Lexer();
    ~Lexer();
    
    Token createToken(TokenType, std::string);
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
