# edit this makefile so that running make compiles your enigma program
CC = g++
CFLAGS = -Wall -g

src/reflector.o: src/reflector.cpp src/reflector.h
	${CC} ${CFLAGS} -c src/reflector.cpp

src/rotor.o: src/rotor.cpp src/rotor.h
	${CC} ${CFLAGS} -c src/rotor.cpp

src/plugboard.o: src/plugboard.cpp src/plugboard.h
	${CC} ${CFLAGS} -c src/plugboard.cpp

Main.o: src/Main.cpp src/reflector.h src/rotor.h src/plugboard.h
	${CC} ${CFLAGS} -c main.cpp

enigma: Main.o reflector.o rotor.o plugboard.o
	${CC} -g Main.o reflector.o rotor.o plugboard.o -o enigma Main.o

clean:
	rm -rf enigma *.o

.PHONY: clean
