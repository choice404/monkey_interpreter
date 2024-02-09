/*
 * Copyright (C) 2024 Austin Choi
 * See end of file for extended copyright information
 */

#pragma once

#include <iostream>
#include <unordered_map>

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
    MINUS,
    BANG,
    ASTERISK,
    SLASH,
    LT,
    GT,
    TRUE,
    FALSE,
    IF,
    ELSE,
    RETURN,
    EQ,
    NOT_EQ,
};

extern const char* TokenMap[27];

/* extern std::unordered_map<TokenType, std::string> TokenMap; */

struct Token
{
    TokenType type;
    std::string literal;
};

class Lexer
{
public:
    Lexer();
    Lexer(std::string);
    ~Lexer();
    
    Token getNextToken();

    std::string getInput();
    char peekChar();

private:
    std::string input;
    int position;
    int readPosition;
    char ch;
    std::unordered_map<std::string, TokenType> keywords
    {
        {"fn", TokenType::FUNCTION},
        {"let", TokenType::LET},
        {"true", TokenType::TRUE},
        {"false", TokenType::FALSE},
        {"if", TokenType::IF},
        {"else", TokenType::ELSE},
        {"return", TokenType::RETURN},
    };

    Token createToken(TokenType, std::string);
    void readChar();
    bool isLetter(char);
    bool isDigit(char);
    std::string readIdentifier();
    std::string readNumber();
    void skipWhitespace();
    TokenType lookupIdentifier(std::string);
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
