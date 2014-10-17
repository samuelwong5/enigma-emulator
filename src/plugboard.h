#pragma once
class Plugboard {
    int* map_;
public:
    Plugboard(char* c);
    int get(int x);
    void print();
};
