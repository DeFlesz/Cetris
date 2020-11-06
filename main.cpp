#include <iostream>
#include "cetris.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <stdlib.h>
#include <unistd.h>

using namespace std;
int main() {
    Cetris map;
    srand(time(NULL));
    map.init();
    map.blocks.summonShape(rand() % 7 + 1, 0, 0);
    //cout << map.blocks.cell[0][0] << map.blocks.cell[0][1];
    while (1){
        usleep(6*10000);
        system("clear");
        map.update();
        map.scanInput();
    }
    
    return 0;
}