#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "rotor.h"
using namespace std;

Rotor::Rotor(){

}

void Rotor::init(string f)
{
    string s;
	ifstream input(f.c_str());
    map = new int[26];
	if (input.is_open()){
        for (int i = 0; i < 26; i++){
            getline(input, s, ' ');
            map[i] = atoi(s.c_str());
        }
    } else {
        exit(1);
    }
	input.close();
	generateInverse();
}

int Rotor::get(int x)
{
	return map[x];
}

int Rotor::inv_get(int x)
{
	return map_inv[x];
}

void Rotor::rotate(void)
{
	int hold = map[0];
	for (int i = 0; i < 25; i++){
		map[i] = map[i + 1];
	}
	map[25] = hold;
	generateInverse();
}

void Rotor::generateInverse(void)
{
	map_inv = new int[26];
	for (int i = 0; i < 26; i++){
		map_inv[map[i]] = i;
	}
}
