/*
 * Copyright (C) 2024 Austin Choi
 * See end of file for extended copyright information
 */

// Include header files
#include <iostream>
#include "./header/lexer.h"
#include "./header/parser.h"

// Preprocessor macro
#define Log(x) (std::cout << x << std::endl)

int main(int argc, char* argv[])
{
    Log("Testing getNextToken()");
    const std::string input = "let five = 5;"
        "let ten = 10;"
        "let foobar = 838383;";

    // Create lexer
    Lexer lexer(input);
    Parser parser(lexer);

    Program* program = parser.parseProgram();

    if(program == nullptr)
    {
        Log("Parser returned nullptr");
        return 1;
    }
    if(program->statements.size() != 3)
    {
        Log("Program does not contain 3 statements");
        return 1;
    }
    
    /* tests = */ 

    Log("Input: " << lexer.getInput());

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
