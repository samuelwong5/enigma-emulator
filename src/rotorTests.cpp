#include <iostream>
#include <cstdlib>
#include "rotor.h"

int main(int argc, char **argv)
{
  Rotor rotor;
  for(int i = 1; i < argc; i++){
      rotor.init(argv[i]);
      for(int j=0; j < 27; j++){
          if(rotor.checkMapping()){
              rotor.rotate();
          } else {
              cout << "ERROR: Rotor with input file " << argv[i] << " failed at rotation " << j << "\n";
              rotor.print();
              exit(1);
          }
      }
      cout << "PASS: Rotor with input file " << argv[i] << "\n";
  }
}
