#include <iostream>
#include "cetris.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;
int main() {
    Cetris map;
    srand(time(NULL));
    map.init();
    map.update();
    map.blocks.summonShape(rand() % 7 + 1);
    cout << map.blocks.parts[1][1];

    return 0;
}
