/*
 * Copyright (C) 2024 Austin Choi
 * See end of file for extended copyright information
 */

// Include header files
#include <iostream>
#include "../header/lexer.h"

// Preprocessor macro
#define Log(x) (std::cout << x << std::endl)

std::unordered_map<TokenType, std::string> TokenMap = {
  {TokenType::ILLEGAL, "ILLEGAL"},
  {TokenType::ENDOFFILE, ""},
  {TokenType::IDENT, "IDENT"},
  {TokenType::INT, "INT"},
  {TokenType::ASSIGN, "="},
  {TokenType::PLUS, "+"},
  {TokenType::COMMA, ","},
  {TokenType::SEMICOLON, ";"},
  {TokenType::LPAREN, "("},
  {TokenType::RPAREN, ")"},
  {TokenType::LBRACE, "{"},
  {TokenType::RBRACE, "}"},
  {TokenType::FUNCTION, "FUNCTION"},
  {TokenType::LET, "LET"},
  {TokenType::MINUS, "-"},
  {TokenType::BANG, "!"},
  {TokenType::ASTERISK, "*"},
  {TokenType::SLASH, "/"},
  {TokenType::LT, "<"},
  {TokenType::GT, ">"},
  {TokenType::TRUE, "TRUE"},
  {TokenType::FALSE, "FALSE"},
  {TokenType::IF, "IF"},
  {TokenType::ELSE, "ELSE"},
  {TokenType::RETURN, "RETURN"},
  {TokenType::EQ, "=="},
  {TokenType::NOT_EQ, "!="},
};

Lexer::Lexer()
{
}

Lexer::~Lexer()
{
}

Lexer::Lexer(std::string input) : input(input), position(0), readPosition(0), ch(0)
{
    this->readChar();
}

Token Lexer::createToken(TokenType type, std::string literal)
{
    Token token;
    token.type = type;
    token.literal = literal;
    return token;
}

Token Lexer::getNextToken()
{
    Token token;
    this->skipWhitespace();
    std::string character(1, this->ch);
    switch(this->ch)
    {
        case '=':
            if(this->peekChar() == '=')
            {
                character += this->peekChar();
                this->readChar();
                token = createToken(TokenType::EQ, character);
            } else
            {
                token = createToken(TokenType::ASSIGN, character);
            }
            break;;
        case ';':
            token = createToken(TokenType::SEMICOLON, character);
            break;;
        case '(':
            token = createToken(TokenType::LPAREN, character);
            break;;
        case ')':
            token = createToken(TokenType::RPAREN, character);
            break;;
        case ',':
            token = createToken(TokenType::COMMA, character);
            break;;
        case '+':
            token = createToken(TokenType::PLUS, character);
            break;;
        case '{':
            token = createToken(TokenType::LBRACE, character);
            break;;
        case '}':
            token = createToken(TokenType::RBRACE, character);
            break;;
        case '-':
            token = createToken(TokenType::MINUS, character);
            break;;
        case '!':
            if(this->peekChar() == '=')
            {
                character += this->peekChar();
                this->readChar();
                token = createToken(TokenType::NOT_EQ, character);
            } else
            {
                token = createToken(TokenType::BANG, character);
            }
            break;;
        case '*':
            token = createToken(TokenType::ASTERISK, character);
            break;;
        case '/':
            token = createToken(TokenType::SLASH, character);
            break;;
        case '<':
            token = createToken(TokenType::LT, character);
            break;;
        case '>':
            token = createToken(TokenType::GT, character);
            break;;
        case '\0':
            token = createToken(TokenType::ENDOFFILE, "");
            break;;
        default:
            if(isLetter(this->ch))
            {
                token.literal = this->readIdentifier();
                token.type = lookupIdentifier(token.literal);
                return token;
            } else if (isDigit(this->ch))
            {
                token.literal = this->readNumber();
                token.type = TokenType::INT;
                return token;
            } else
            {
                token = createToken(TokenType::ILLEGAL, character);
            }
            break;;
    }
    this->readChar();
    return token;
}

void Lexer::readChar()
{
    if(this->readPosition >= this->input.length())
    {
        this->ch = 0;
    }
    else
    {
        this->ch = this->input[this->readPosition];
    }
    this->position = this->readPosition++;
}

std::string Lexer::readIdentifier()
{
    int position = this->position;
    while(isLetter(this->ch))
    {
        this->readChar();
    }
    return this->input.substr(position, this->position - position);
}

bool Lexer::isLetter(char ch)
{
    return 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z' || ch == '_';
}

TokenType Lexer::lookupIdentifier(std::string identifier)
{
    if(this->keywords.find(identifier) != this->keywords.end())
    {
        return this->keywords[identifier];
    }
    return TokenType::IDENT;
}

void Lexer::skipWhitespace()
{
    while(this->ch == ' ' || this->ch == '\t' || this->ch == '\n' || this->ch == '\r')
    {
        this->readChar();
    }
}

std::string Lexer::readNumber()
{
    int position = this->position;
    while(isDigit(this->ch))
    {
        this->readChar();
    }
    return this->input.substr(position, this->position - position);
}

bool Lexer::isDigit(char ch)
{
    return '0' <= ch && ch <= '9';
}

std::string Lexer::getInput()
{
    return this->input;
}

char Lexer::peekChar()
{
    if(this->readPosition >= this->input.length())
    {
        return 0;
    }
    else
    {
        return this->input[this->readPosition];
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
