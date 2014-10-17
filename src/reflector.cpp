#include "reflector.h"
int Reflector::reflect(int x)
{
    return (x + 13) % 26;      // ROT13
}
