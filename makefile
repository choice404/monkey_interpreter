REPL				= ./repl.cpp
LEXER				= ./lexer_test.cpp
INCLUDES		= ./source/*.cpp
REPL_INCLUDES	= ./source/lexer.cpp ./source/repl.cpp
LEXER_INCLUDES	= ./source/lexer.cpp
CFLAGS			= -std=c++11
REPL_OUT		= ./repl
LEXER_OUT		= ./lexer_test
CC					= g++

all: repl lexer

repl: repl.cpp
	$(CC) $(CFLAGS) $(REPL_INCLUDES) $(REPL) -o $(REPL_OUT)

lexer: lexer_test.cpp
	$(CC) $(CFLAGS) $(LEXER_INCLUDES) $(LEXER) -o $(LEXER_OUT)

clean:
	rm -rf $(REPL_OUT) $(LEXER_OUT)
