CC = g++
CFLAGS = -Wall -g

all: reflector.o rotor.o plugboard.o encryptor.o

encryptor.o: encryptor.cpp encryptor.h
    $(CC) $(CFLAGS) -c encryptor.cpp
 
plugboard.o: plugboard.cpp plugboard.h
	${CC} ${CFLAGS} -c plugboard.cpp
   
reflector.o: reflector.cpp reflector.h
	${CC} ${CFLAGS} -c reflector.cpp

rotor.o: rotor.cpp rotor.h
	${CC} ${CFLAGS} -c rotor.cpp