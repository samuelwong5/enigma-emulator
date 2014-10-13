#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "rotor.h"
using namespace std;

Rotor::Rotor(){
    rotatecount = 0;
}

void Rotor::init(string f)
{
    string s;
	ifstream input(f.c_str());
    map = new int[26]; map_inv = new int[26];
	if (input.is_open()){
        for (int i = 0; i < 26; i++){
            getline(input, s, ' ');
            map[i] = atoi(s.c_str());
        }
        for (int i = 0; i < 25; i++){
            for (int j = 0; j < 25; j++){
                if(map[i]==map[j]&&i!=j){
                    cout << "ERROR: Mapping both " << i << " and " << j << " to " << map[i] << "\n";
                }
            }
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

bool Rotor::rotate(void)
{
    rotatecount++;
    int hold = map[0] - 1;
    if(hold<0){ hold += 26; }
	for (int i = 0; i < 25; i++){
        map[i] = map[i+1] - 1;
        if(map[i]<0){ map[i] += 26; }
	}
    map[25] = hold;
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < 26; j++){
            if(map[i]==map[j]&&i!=j){
                cout << "\nERROR: Mapping both " << i << " and "
                     << j << " to " << map[i] << "\n";
            }
        }
    }
	generateInverse();
    if(rotatecount==26){
        rotatecount = 0;
        return true;
    }
    return false;
}

void Rotor::generateInverse(void)
{
	for (int i = 0; i < 26; i++){
		map_inv[map[i]] = i;
	}
    for (int i = 0; i<26; i++){
        if(map_inv[map[i]]!=i){
            cout << "\nERROR: Failed to generate correct inverse\nMapping "
                 << i << " to " << map[i] << " and " << map_inv[map[i]]
                 << " to " << i << "\n";
            printmap(map);
            printmap(map_inv);
            exit(1);
        }
    }
}

void Rotor::printmap(int* map){
    for(int i = 0 ; i < 26 ; i++){
        cout << i << "->" << map[i] << "\n";
    }
}
