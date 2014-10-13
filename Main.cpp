// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>
#include <iostream>
#include <fstream>
#include "src/rotor.h"
#include "src/reflector.h"
#include "src/plugboard.h"

using namespace std;

void encrypt(int x, Reflector& rf, Rotor* rot, Plugboard *pb, int rotc);

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
          int input = (int) c - 'A';
          encrypt(input, rf, rotors, pb, rotcount);
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
      rot[i].rotate();
  }
  out = pb->get(out);
  char output = 'A' + out;
  cout << output;
}


