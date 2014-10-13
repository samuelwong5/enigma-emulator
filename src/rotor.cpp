#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "rotor.h"
using namespace std;

Rotor::Rotor(string f)
{
	string s, hold;
	ifstream input(f.c_str());
	if (input.is_open()){
		getline(input, s);
	}
	input.close();
	istringstream iss(s);
	map = new int[26];
	for (int i = 0; i < 26; i++){
		getline(iss, hold, ' ');
		map[i] = atoi(hold.c_str());
	}
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