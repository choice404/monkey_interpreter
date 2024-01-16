/*
 * Copyright (C) 2024 Austin Choi
 * See end of file for extended copyright information
 */

#pragma once

#include <iostream>

class Repl
{
public:
    Repl();
    ~Repl();

    void start();

private:
    const char* prompt = ">> ";

    void printPrompt();
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
