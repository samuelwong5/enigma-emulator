#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "rotor.h"
using namespace std;

Rotor::Rotor(string f)
{
    rotatecount_ = 0;                                   // Counts number of rotations
    string s;
    ifstream input(f.c_str());
    map_ = new int[26]; mapInv_ = new int[26];          // Initializing mapping and its inverse
    if (input.is_open()){
        for (int i = 0; i < 26; i++){                   // Getting initial map
            getline(input, s, ' ');
            map_[i] = atoi(s.c_str());
        }
        for (int i = 0; i < 25; i++){                   // Checks mapping is correct (bijective)
            for (int j = 0; j < 25; j++){
                if(map_[i]==map_[j]&&i!=j){
                    cout << "ERROR: Mapping both " << i <<
                        " and " << j << " to " << map_[i] << "\n";
                    exit(1);
                }
            }
        }
    } else {
        exit(1);
    }
    input.close();
    generateInverse();
}


int Rotor::get(int x)                                   // Get mapping
{
    return map_[x];
}

int Rotor::getInverse(int x)                            // Get inverse mapping
{
    return mapInv_[x];
}
 
bool Rotor::rotate(void)                                // Rotate rotor
{
    rotatecount_++;
    int hold = map_[0] - 1;
    if(hold<0){ hold += 26; }
    for (int i = 0; i < 25; i++){
        map_[i] = map_[i + 1] - 1;
        if(map_[i]<0){ map_[i] += 26; }
    }
    map_[25] = hold;
    generateInverse();
    if(rotatecount_==26){
        rotatecount_ = 0;
        return true;
    }
    return false;
}

void Rotor::generateInverse(void)
{
    for (int i = 0; i < 26; i++){
        mapInv_[map_[i]] = i;
    }
}

bool Rotor::checkMapping(void)
{
    for (int i = 0; i < 26; i++){                       // Checks mapping is correct
        for (int j = 0; j < 26; j++){
            if(map_[i]==map_[j]&&i!=j){
                cout << "\nERROR: Mapping both " << i << " and "
                     << j << " to " << map_[i] << "\n";
                return false;
            }
        }
    }
    for (int i = 0; i<26; i++){
        if(mapInv_[map_[i]]!=i){                        // Checks map_inv is inverse of map
            cout << "\nERROR: Failed to generate correct inverse\nMapping "
                 << i << " to " << map_[i] << " and " << mapInv_[map_[i]]
                 << " to " << i << "\n";
            return false;
        }
    }
    return true;
}

void Rotor::print(void)                                 // Prints mapping
{
    for(int i = 0 ; i < 26 ; i++){
        cout << i << "->" << map_[i] << "\n";
    }
    for(int i = 0 ; i < 26 ; i++){
        cout << i << "->" << mapInv_[i] << "\n";
    }
}
