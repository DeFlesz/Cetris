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
    map.blocks.summonShape(rand() % 7 + 1, 0, 0);
    //cout << map.blocks.cell[0][0] << map.blocks.cell[0][1];
    map.update();
    cout << map.map[0][0] << map.map[1][0];
    return 0;
}