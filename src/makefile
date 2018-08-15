all: main

main: main.o syntax.o lexer.o
	clang main.o syntax.o lexer.o -o main.exe

main.o: main.cpp
	clang -c main.cpp

lexer.o: lexer.cpp
	clang -c lexer.cpp

syntax.o: syntax.cpp
	clang -c syntax.cpp
