/*
 * Copyright (C) 2024 Austin Choi
 * See end of file for extended copyright information
 */

// Include header files
#include <iostream>
#include "../header/repl.h"
#include "../header/lexer.h"  

// Preprocessor macro
#define Log(x) (std::cout << x << std::endl)

Repl::Repl()
{
    Log("Repl created");
}

Repl::~Repl()
{
    Log("Repl destroyed");
}

void Repl::start()
{
    while(true)
    {
        printPrompt();
        std::string input;
        std::getline(std::cin, input);
        if(std::cin.eof())
        {
            Log("EOF");
            break;
        }

        if(input == "exit()")
        {
            Log("Exiting");
            break;
        }
        else if(input == "clear()")
        {
            system("clear");
            continue;
        }

        Lexer lexer(input);

        for(Token token = lexer.getNextToken(); token.type != TokenType::ENDOFFILE; token = lexer.getNextToken())
        {
            std::cout << token.type << " " << token.literal << std::endl;
        }
    }
}

void Repl::printPrompt()
{
    std::cout << prompt;
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
