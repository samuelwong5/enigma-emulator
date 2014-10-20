#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include "src/rotor.h"
#include "src/reflector.h"
#include "src/plugboard.h"
#include "src/encryptor.h"

using namespace std;

bool isWhiteSpace(char c);

int main(int argc, char **argv)
{
	Encryptor *encryptor = new Encryptor(argc, argv);                                                  
    for(string line; getline(ws(cin), line);){
        for(char& c : line){
            int input = (int) c - 'A';
            if (input < 0 || input > 25){ exit(1); }                                         // Exit if not A-Z
			if (!isWhiteSpace(c)){ encryptor->encryptChar(input); }
        }
    }
}

bool isWhiteSpace(char c)
{
	if (c == ' ' || c == '\r' || c == "\n" || c == "\t" || c == "\f"){
		return true;
	} 
	return false;
}