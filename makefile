CC = g++
CFLAGS =  -std=c++11
REPL_OUT = repl
LEXER_OUT = lexer
REPL_INCLUDES = ./source/repl.cpp ./source/lexer.cpp
LEXER_INCLUDES = ./source/lexer.cpp
REPL = ./repl.cpp
LEXER = ./lexer_test.cpp

all: repl lexer

repl: $(REPL)
	$(CC) $(CFLAGS) $(REPL) $(REPL_INCLUDES) -o $(REPL_OUT)

lexer: $(LEXER)
	$(CC) $(CFLAGS) $(LEXER) $(LEXER_INCLUDES) -o $(LEXER_OUT)

clean:
	rm -f $(REPL_OUT) $(LEXER_OUT)
