#include <iostream>
#include <fstream>
#include <cstdlib>
#include "plugboard.h"
using namespace std;

Plugboard::Plugboard(char* c)
{
    int x,y;
    map_ = new int[26];
    for (int i = 0; i < 26; i++){          // Initialize mapping
        map_[i] = i;
    }
	ifstream input(c);
	if (input.is_open()){              
        while(input >> x){                // Get mapping pairs
            input >> y;
            map_[x] = y;
            map_[y] = x;
        }
    } else{
        exit(1);
    }
    input.close();
}

int Plugboard::get(int x)                  // Return mapped pair
{
    return map_[x];
}

void Plugboard::print()
{
    for(int i = 0; i < 26; i++){
        cout << i << " -> " << get(i) << "\n";
    }
}
