#include <stdexcept>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "src/rotor.h"
#include "src/reflector.h"
#include "src/plugboard.h"

using namespace std;

void encrypt(int x, Reflector& rf, vector<Rotor>& rotors, Plugboard *pb);
void printCharFromInt(int x);

int main(int argc, char **argv)
{
  Reflector rf;                                                                            // Initializing reflector
  vector<Rotor> rotors;
  for(int i = 1; i < argc - 1; i++){
      rotors.push_back(Rotor(argv[i]));                                                    // Initializing rotors
  }
  Plugboard *pb = new Plugboard(argv[argc-1]);                                             // Initializing plugboard
  for(string line; getline(ws(cin), line);){
      for(char& c : line){
		  if (c == ' ' || c == '\t' || c == '\n') { 
			  // Do nothing
		  } else {
			  int input = (int)c - 'A';
              if (input < 0 || input > 25){ exit(1); }                                     // Exit if not A-Z
              encrypt(input, rf, rotors, pb);
              for (vector<Rotor>::iterator it = rotors.begin(); it!= rotors.end(); ++it){  // Rotate
                  if(!(it->rotate())){
                      break;
                  }
              }
		  }
      }
      cout << "\n";
  }
}

void encrypt(int x, Reflector& rf, vector<Rotor>& rotors, Plugboard *pb)
{
  if(x < 0 || x > 25){
      cout << "Trying to encrypt non A-Z character\n";
      exit(1);
  }
  int out = pb->get(x);                                                                    // First pass through plugboard

  for (vector<Rotor>::iterator it = rotors.begin(); it!= rotors.end(); ++it){              // Passing through all rotors
      out = it->get(out);
  }
  out = rf.reflect(out);                                                                   // Passing through reflector
  for (vector<Rotor>::reverse_iterator rit = rotors.rbegin(); rit!= rotors.rend(); ++rit){ // Passing through all inverse rotors
      out = rit->getInverse(out);
  }
  out = pb->get(out);                                                                      // Second pass through plugboard
  printCharFromInt(out);
}

void printCharFromInt(int x)                                                                      // Print A-Z from 0-25
{
  char output = 'A' + x;
  cout << output;
}
