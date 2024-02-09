/*
 * Copyright (C) 2024 Austin Choi
 * See end of file for extended copyright information
 */

// Include header files
#include <iostream>
#include "./header/repl.h"
#include "./header/lexer.h"

// Preprocessor macro
#define Log(x) (std::cout << x << std::endl)

int main(int argc, char* argv[])
{

    Log("Starting interpreter");
    Log("Welcome to the Monkey programming language!");
    Log("Feel free to type in commands");
    Repl repl;
    repl.start();

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
