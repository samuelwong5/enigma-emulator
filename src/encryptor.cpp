#include <iostream>
#include <fstream>
#include <cstdlib>
#include "encryptor.h"
#include "rotor.h"
#include "plugboard.h"
#include "reflector.h"

using namespace std;

Encryptor::Encryptor(int argc, char **argv)
{
	for (int i = 1; i < argc - 1; i++){
		rotors_.push_back(Rotor(argv[i]));                                                        // Initializing rotors
	}
	plugboard_ = new Plugboard(argv[argc - 1]);                                                  // Initializing plugboard
}

void Encryptor::encryptChar(int input)
{
	int output = plugboard_->get(input);                                                         // First pass through plugboard

	for (vector<Rotor>::iterator it = rotors_.begin(); it != rotors_.end(); ++it){               // Passing through all rotors
		output = it->get(output);
	}
	output = reflector_.reflect(output);                                                         // Passing through reflector
	for (vector<Rotor>::reverse_iterator rit = rotors_.rbegin(); rit != rotors_.rend(); ++rit){  // Passing through all inverse rotors
		output = rit->getInverse(output);
	}
	output = plugboard_->get(output);                                                            // Second pass through plugboard
	printCharFromInt(output);
	for (vector<Rotor>::iterator it = rotors_.begin(); it != rotors_.end(); ++it){               // Rotate
		if (!(it->rotate())){
			break;
		}
	}
}

void Encryptor::printCharFromInt(int x)                                                          // Print A-Z from 0-25
{
	char output = 'A' + x;
	cout << output;
}
