#pragma once
#include <string>
class Plugboard {
    int* map_;
public:
	Plugboard(std::string f);
	int get(int x);
    void print();
};
