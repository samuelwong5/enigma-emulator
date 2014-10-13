#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "plugboard.h"
using namespace std;

Plugboard::Plugboard(string f)
{
	string s, hold1, hold2;
	ifstream input(f.c_str());
	if (input.is_open()){
		getline(input, s);
	}
	input.close();
	istringstream iss(s);
	map = new int[26];
	for (int i = 0; i < 26; i++){
		map[i] = i;
	}
	while (getline(iss, hold1, ' '))
	{
		getline(iss, hold2, ' ');
		int i = atoi(hold1.c_str()), j = atoi(hold2.c_str());
		map[i] = j;
		map[j] = i;
	}
}

int Plugboard::get(int x)
{
	return map[x];
}

