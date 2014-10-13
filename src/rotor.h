#include <string>
using namespace std;
class Rotor {
	int *map, *map_inv;
public:
	Rotor(string f);
	int get(int x);
	int inv_get(int x);
	void rotate(void);
	void generateInverse(void);
};
