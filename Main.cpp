#include <stdexcept>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "src/rotor.h"
#include "src/reflector.h"
#include "src/plugboard.h"

using namespace std;

void encrypt(int x, Reflector& rf, Rotor* rot, Plugboard *pb, int rotc);
void printchar(int x);

int main(int argc, char **argv)
{
  int rotcount = argc - 2;                              // Number of rotors
  Reflector rf;                                         // Initializing reflector
  Rotor *rotors = new Rotor[argc-2];
  for(int i=1; i<argc-1; i++){
      rotors[i-1].init(argv[i]);                        // Initializing rotors
  }
  Plugboard *pb = new Plugboard(argv[argc-1]);          // Initializing plugboard
  for(string line; getline(cin, line);){
      for(char& c : line){
		  if (c == ' ' || c == '\t' || c == '\n') { 
			  // Do nothing as whitespace is ignored
		  } else {
			  int input = (int)c - 'A';
			  if (input<0 || input>25){ exit(1); }      // Exit if not A-Z
			  encrypt(input, rf, rotors, pb, rotcount);
			  int i = 0;
			  while (i < rotcount&&rotors[i].rotate()){ // Rotoate rotors
				  i++; 
			  } 
		  }
      }
      cout << "\n";
  }
}

void encrypt(int x, Reflector& rf, Rotor* rot, Plugboard *pb, int rotc){
  int out = pb->get(x);                                // First pass through plugboard 
  for(int i=0; i<rotc; i++){                           // Passing through all rotors
      out = rot[i].get(out);
  }
  out = rf.reflect(out);                               // Passing through reflector
  for(int i=rotc-1; i>=0; i--){                        // Passing through all rotor inverses
      out = rot[i].inv_get(out);
  }
  out = pb->get(out);                                  // Second pass through plugboard
  printchar(out);
}

void printchar(int x){                                 // Print A-Z from 0-25
  char output = 'A' + x;
  cout << output;
}
