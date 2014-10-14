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
  int rotcount = argc - 2;
  Reflector rf;
  Rotor *rotors = new Rotor[argc-2];
  for(int i=1; i<argc-1; i++){
      rotors[i-1].init(argv[i]);
  }
  Plugboard *pb = new Plugboard(argv[argc-1]);
  for(string line; getline(cin, line);){
      for(char& c : line){
		  if (c == ' ' || c == '\t' || c == '\n') { 
			  cout << c; 
		  }
		  else {
			  int input = (int)c - 'A';
			  if (input<0 || input>25){ exit(1); }
			  encrypt(input, rf, rotors, pb, rotcount);
			  int i = 0;
			  while (i < rotcount&&rotors[i].rotate()){ i++; }
		  }
      }
      cout << "\n";
  }
}

void encrypt(int x, Reflector& rf, Rotor* rot, Plugboard *pb, int rotc){
  int out = pb->get(x);
  for(int i=0; i<rotc; i++){
      out = rot[i].get(out);
  }
  out = rf.reflect(out);
  for(int i=rotc-1; i>=0; i--){
      out = rot[i].inv_get(out);
  }
  out = pb->get(out);
  printchar(out);
}

void printchar(int x){
  char output = 'A' + x;
  cout << output;
}
