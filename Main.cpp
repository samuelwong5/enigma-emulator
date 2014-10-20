#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include "src/rotor.h"
#include "src/reflector.h"
#include "src/plugboard.h"
#include "src/encryptor.h"

using namespace std;

int main(int argc, char **argv)
{
	Encryptor *encryptor = new Encryptor(argc, argv);                                                  
    for(string line; getline(ws(cin), line);){
        for(char& c : line){
            int input = (int) c - 'A';
            if (input < 0 || input > 25){ exit(1); }                                         // Exit if not A-Z
            encryptor->encryptChar(input);        
        }
    }
}
