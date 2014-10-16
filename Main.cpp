#include <stdexcept>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "src/rotor.h"
#include "src/reflector.h"
#include "src/plugboard.h"

using namespace std;

void encrypt(int input, Reflector& reflector, vector<Rotor>& rotors, Plugboard *plugboard);
void printCharFromInt(int x);

int main(int argc, char **argv)
{
  Reflector reflector;                                                                     // Initializing reflector
  vector<Rotor> rotors;
  for(int i = 1; i < argc - 1; i++){
      rotors.push_back(Rotor(argv[i]));                                                    // Initializing rotors
  }
  Plugboard *plugboard = new Plugboard(argv[argc-1]);                                      // Initializing plugboard
  for(string line; getline(ws(cin), line);){
      for(char& c : line){
          if (c == ' ' || c == '\t' || c == '\n' || c == '\t' || c == '\f') {
			  // Do nothing
		  } else {
			  int input = (int)c - 'A';
              if (input < 0 || input > 25){ exit(1); }                                     // Exit if not A-Z
              encrypt(input, reflector, rotors, plugboard);
              for (vector<Rotor>::iterator it = rotors.begin(); it!= rotors.end(); ++it){  // Rotate
                  if(!(it->rotate())){
                      break;
                  }
              }
		  }
      }
  }
}

void encrypt(int input, Reflector& reflector, vector<Rotor>& rotors, Plugboard *plugboard)
{
  if(input < 0 || input > 25){
      cout << "Trying to encrypt non A-Z character\n";
      exit(1);
  }
  int output = plugboard->get(input);                                                      // First pass through plugboard

  for (vector<Rotor>::iterator it = rotors.begin(); it!= rotors.end(); ++it){              // Passing through all rotors
      output = it->get(output);
  }
  output = reflector.reflect(output);                                                      // Passing through reflector
  for (vector<Rotor>::reverse_iterator rit = rotors.rbegin(); rit!= rotors.rend(); ++rit){ // Passing through all inverse rotors
      output = rit->getInverse(output);
  }
  output = plugboard->get(output);                                                         // Second pass through plugboard
  printCharFromInt(output);
}

void printCharFromInt(int x)                                                               // Print A-Z from 0-25
{
  char output = 'A' + x;
  cout << output;
}
