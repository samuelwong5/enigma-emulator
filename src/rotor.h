#include <string>
using namespace std;
class Rotor {
	int *map, *map_inv;
    int rotatecount;
public:
    Rotor();
    void init(string f);
	int get(int x);
	int inv_get(int x);
    bool rotate(void);
	void generateInverse(void);
    void printmap(int* map);
};
