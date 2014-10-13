# edit this makefile so that running make compiles your enigma program
CC = g++
CFLAGS = -Wall -g -std=c++11

all: enigma

Main.o: Main.cpp src/reflector.h src/rotor.h src/plugboard.h
	${CC} ${CFLAGS} -c Main.cpp

enigma: Main.o src/reflector.o src/rotor.o src/plugboard.o
	${CC} -g Main.o src/reflector.o src/rotor.o src/plugboard.o -o enigma

clean:
	rm -rf enigma *.o

.PHONY: clean
