#include <string>
class Plugboard {
	int* map;
public:
	Plugboard(std::string f);
	int get(int x);
    void print();
};
