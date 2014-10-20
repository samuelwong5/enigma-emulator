#pragma once
#include <vector>
#include "rotor.h"
#include "plugboard.h"
#include "reflector.h"

class Encryptor {
	Reflector reflector_;
	std::vector<Rotor> rotors_;
	Plugboard *plugboard_;
public:
	Encryptor(int argc, char **argv);
	void encryptChar(int input);
	void printCharFromInt(int x);
};