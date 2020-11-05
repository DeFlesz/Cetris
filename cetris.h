#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;
class Blocks {
    public:
    int parts[4][4];
    void summonShape(int figure_id){
        for (int y = 0; y < 3; y++){
            for (int x = 0; x < 3; x++){
                parts[x][y] = false;
            }
        }
        switch (figure_id)
        {
            case 1: //square
                parts[1][1] = true;
                parts[1][2] = true;
                parts[2][1] = true;
                parts[2][2] = true;
                break;

            case 2: //line
                parts[2][0] = true;
                parts[2][1] = true;
                parts[2][2] = true;
                parts[2][3] = true;
                break;

            case 3: //t-shape
                parts[2][0] = true;
                parts[1][1] = true;
                parts[2][1] = true;
                parts[3][1] = true;
                break;

            case 4: //lighting-normal
                parts[1][1] = true;
                parts[2][1] = true;
                parts[2][0] = true;
                parts[3][0] = true;
                break;

            case 5: //lighting-mirror
                parts[1][0] = true;
                parts[2][0] = true;
                parts[2][1] = true;
                parts[3][1] = true;
                break;
            
            case 6: //l-shape-normal
                parts[1][0] = true;
                parts[2][0] = true;
                parts[3][0] = true;
                parts[3][1] = true;
                break;

            case 7: //l-shape-mirror
                parts[1][1] = true;
                parts[1][0] = true;
                parts[2][0] = true;
                parts[3][0] = true;
                break;
        }
    }
};

class Cetris {
    public:
        const int MAP_WIDTH = 10;
        const int MAP_HEIGHT = 20;
        bool map[10][20];
        Blocks blocks;

    void createMap(){
        for (int y = 0; y <= MAP_HEIGHT-1; y++){
            for (int x = 0; x <= MAP_WIDTH-1; x++){
                map[x][y] = false;
            }
        }
    }

    void update(){
        for (int y = 0; y <= MAP_HEIGHT-1; y++){
            for (int x = 0; x <= MAP_WIDTH-1; x++){
                if (map[x][y] == false){
                    cout << ".";
                } else {
                    cout << "#";
                }
            }
            cout << endl;
        }
    }

    void init(){
        Cetris::createMap();
        Cetris::update();
    }
};