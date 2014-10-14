#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "plugboard.h"
using namespace std;

Plugboard::Plugboard(string f)
{
    string s;
    int x,y;
    map = new int[26];
    for (int i = 0; i < 26; i++){          // Initialize mapping
        map[i] = i;
    }
	ifstream input(f.c_str());
	if (input.is_open()){              
        while(getline(input, s, ' ')){     // Get mapping pairs
            x = atoi(s.c_str());
            getline(input, s, ' ');
            y = atoi(s.c_str());
            map[x] = y;
			map[y] = x;
        }
    } else{
        exit(1);
    }
    input.close();
}

int Plugboard::get(int x)                  // Return mapped pair
{
	return map[x];
}

