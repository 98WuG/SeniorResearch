CC=g++
CFLAGS=-I

main: main.cpp rectangle.cpp rectangle.h
	$(CC) -o main main.cpp rectangle.cpp
