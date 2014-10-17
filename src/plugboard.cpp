#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "plugboard.h"
using namespace std;

Plugboard::Plugboard(char* c)
{
    string s;
    int x,y;
    map_ = new int[26];
    for (int i = 0; i < 26; i++){          // Initialize mapping
        map_[i] = i;
    }
	ifstream input(c);
	if (input.is_open()){              
        while(getline(input, s, ' ')){     // Get mapping pairs
            x = atoi(s.c_str());
            getline(input, s, ' ');
            y = atoi(s.c_str());
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
