#include <string>
using namespace std;
class Rotor {
	int *map, *map_inv;
    int rotatecount;
public:
    Rotor(string f);
	int get(int x);
    int getInverse(int x);
    bool rotate(void);
    bool checkMapping(void);
	void generateInverse(void);
    void print(void);
    void init(string f);
};
