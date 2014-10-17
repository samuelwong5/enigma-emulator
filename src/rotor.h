#pragma once
#include <string>
using namespace std;
class Rotor {
    int *map_, *mapInv_;
    int rotatecount_;
public:
    Rotor(string f);
    int get(int x);
    int getInverse(int x);
    bool rotate(void);
    bool checkMapping(void);
    void generateInverse(void);
    void print(void);
};
