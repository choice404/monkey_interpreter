/*
 * Copyright (C) 2024 Austin Choi
 * See end of file for extended copyright information
 */

// Include header files
#include <iostream>
#include "./header/lexer.h"

// Preprocessor macro
#define Log(x) (std::cout << x << std::endl)

int main(int argc, char* argv[])
{
    Log("Testing getNextToken()");
    const std::string input = "let five = 5"
        "; let ten = 10;"
        "let add = fn(x, y) {"
        "x + y;"
        "};"
        "let result = add(five, ten);"
        "!-/*5;"
        "5 < 10 > 5;"
        "if (5 < 10) {"
        "return true;"
        "} else {"
        "return false;"
        "}"
        "10 == 10;"
        "10 != 9;";

    /* const std::string input = "let five = 5;\n let ten = 10;\n let add = fn(x, y) {\n x + y;\n};\nlet result = add(five, ten);"; */
    const int TESTSIZE = 74;

    TokenType testTypes[TESTSIZE] = {
        TokenType::LET,
        TokenType::IDENT,
        TokenType::ASSIGN,
        TokenType::INT,
        TokenType::SEMICOLON,
        TokenType::LET,
        TokenType::IDENT,
        TokenType::ASSIGN,
        TokenType::INT,
        TokenType::SEMICOLON,
        TokenType::LET,
        TokenType::IDENT,
        TokenType::ASSIGN,
        TokenType::FUNCTION,
        TokenType::LPAREN,
        TokenType::IDENT,
        TokenType::COMMA,
        TokenType::IDENT,
        TokenType::RPAREN,
        TokenType::LBRACE,
        TokenType::IDENT,
        TokenType::PLUS,
        TokenType::IDENT,
        TokenType::SEMICOLON,
        TokenType::RBRACE,
        TokenType::SEMICOLON,
        TokenType::LET,
        TokenType::IDENT,
        TokenType::ASSIGN,
        TokenType::IDENT,
        TokenType::LPAREN,
        TokenType::IDENT,
        TokenType::COMMA,
        TokenType::IDENT,
        TokenType::RPAREN,
        TokenType::SEMICOLON,
        TokenType::BANG,
        TokenType::MINUS,
        TokenType::SLASH,
        TokenType::ASTERISK,
        TokenType::INT,
        TokenType::SEMICOLON,
        TokenType::INT,
        TokenType::LT,
        TokenType::INT,
        TokenType::GT,
        TokenType::INT,
        TokenType::SEMICOLON,
        TokenType::IF,
        TokenType::LPAREN,
        TokenType::INT,
        TokenType::LT,
        TokenType::INT,
        TokenType::RPAREN,
        TokenType::LBRACE,
        TokenType::RETURN,
        TokenType::TRUE,
        TokenType::SEMICOLON,
        TokenType::RBRACE,
        TokenType::ELSE,
        TokenType::LBRACE,
        TokenType::RETURN,
        TokenType::FALSE,
        TokenType::SEMICOLON,
        TokenType::RBRACE,
        TokenType::INT,
        TokenType::EQ,
        TokenType::INT,
        TokenType::SEMICOLON,
        TokenType::INT,
        TokenType::NOT_EQ,
        TokenType::INT,
        TokenType::SEMICOLON,
        TokenType::ENDOFFILE,
    };

    std::string testLiterals[TESTSIZE] = {
        "let",
        "five",
        "=",
        "5",
        ";",
        "let",
        "ten",
        "=",
        "10",
        ";",
        "let",
        "add",
        "=",
        "fn",
        "(",
        "x",
        ",",
        "y",
        ")",
        "{",
        "x",
        "+",
        "y",
        ";",
        "}",
        ";",
        "let",
        "result",
        "=",
        "add",
        "(",
        "five",
        ",",
        "ten",
        ")",
        ";",
        "!",
        "-",
        "/",
        "*",
        "5",
        ";",
        "5",
        "<",
        "10",
        ">",
        "5",
        ";",
        "if",
        "(",
        "5",
        "<",
        "10",
        ")",
        "{",
        "return",
        "true",
        ";",
        "}",
        "else",
        "{",
        "return",
        "false",
        ";",
        "}",
        "10",
        "==",
        "10",
        ";",
        "10",
        "!=",
        "9",
        ";",
        "",
    };

    // Create lexer
    Lexer lexer(input);

    Log("Input: " << lexer.getInput());

    for(int i = 0; i < TESTSIZE; ++i)
    {
        Token token = lexer.getNextToken();
        if(token.type != testTypes[i])
        {
            Log("TokenType Error: Expected " << testTypes[i] << " got " << token.type);
            Log("Expected literal: " << testLiterals[i] << " got literal " << token.literal);
            return 1;
        }
        if(token.literal != testLiterals[i])
        {
            Log("TokenLiteral Error: Expected " << testLiterals[i] << " got " << token.literal);
            Log("Expected type: " << testTypes[i] << " got type " << token.type);
            return 1;
        }
        Log("Token Type " << testTypes[i] << " and Token Literal " << testLiterals[i]);
    }

    std::cout << "Test passed" << std::endl;

    // End program
    return 0;
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
