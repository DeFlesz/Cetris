#include <iostream>
#include "wincetris.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <stdlib.h>
#include <unistd.h>

Cetris map;

void printEndScreen(){
    system("cls");
    cout << endl << "$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
    cout << "$          $              $" << endl;
    cout << "$          $              $" << endl;
    cout << "$          $              $" << endl;
    cout << "$          $              $" << endl;
    cout << "$          $              $" << endl;
    cout << "$          $              $" << endl;
    cout << "$    $$$$$$$$$$$$$$$$     $" << endl;
    cout << "$    $              $     $" << endl;
    cout << "$    $   GAME OVER  $     $" << endl;
    cout << "$    $              $     $" << endl;
    cout << "$    $   SCORE: " << map.score;
    for (int n = 4; n > map.nos.length(); n--){
        cout << " ";
    }
    cout << "$     $" << endl;
    cout << "$    $              $     $" << endl;
    cout << "$    $$$$$$$$$$$$$$$$     $" << endl;
    cout << "$          $              $" << endl;
    cout << "$          $              $" << endl;
    cout << "$          $              $" << endl;
    cout << "$          $              $" << endl;
    cout << "$          $              $" << endl;
    cout << "$          $              $" << endl;
    cout << "$ game by: GitHub/DeFlesz $" << endl;
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
}

using namespace std;
int main() {
    system("cls");
    srand(time(NULL));
    map.init();
    //map.blocks.summonShape(rand() % 7 + 1, 0, 0);
    map.blocks.summonShape(2, 0, 0);
    //cout << map.blocks.cell[0][0] << map.blocks.cell[0][1];
    while (1){
        //usleep(6*10000);
        map.update();
        system("cls");
        if (map.inGame == false){
                printEndScreen();
                system("pause");
            return 0;
        }
    }

    return 0;
}
