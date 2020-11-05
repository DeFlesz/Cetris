#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;
class Blocks {
    public:
    int cell[4][2];
    int figureShape;
    void summonShape(int figure_id,int cell_pos_x,int cell_pos_y){
        switch (figure_id)
        {
            case 1: //square
                //root part
                cell[0][0] = cell_pos_x+4;
                cell[0][1] = cell_pos_y;

                cell[1][0] = cell_pos_x+5;
                cell[1][1] = cell_pos_y;

                cell[2][0] = cell_pos_x+4;
                cell[2][1] = cell_pos_y+1;

                cell[3][0] = cell_pos_x+5;
                cell[3][1] = cell_pos_y+1;
                
                break;

            case 2: //line
                //root part
                cell[0][0] = cell_pos_x+3;
                cell[0][1] = cell_pos_y;

                cell[1][0] = cell_pos_x+4;
                cell[1][1] = cell_pos_y;

                cell[2][0] = cell_pos_x+5;
                cell[2][1] = cell_pos_y;

                cell[3][0] = cell_pos_x+6;
                cell[3][1] = cell_pos_y;
                break;

            case 3: //t-shape
                //root part
                cell[0][0] = cell_pos_x+3;
                cell[0][1] = cell_pos_y;

                cell[1][0] = cell_pos_x+4;
                cell[1][1] = cell_pos_y;

                cell[2][0] = cell_pos_x+5;
                cell[2][1] = cell_pos_y;

                cell[3][0] = cell_pos_x+4;
                cell[3][1] = cell_pos_y+1;
                break;

            case 4: //lighting-normal
                //root part
                cell[0][0] = cell_pos_x+4;
                cell[0][1] = cell_pos_y;

                cell[1][0] = cell_pos_x+5;
                cell[1][1] = cell_pos_y;

                cell[2][0] = cell_pos_x+3;
                cell[2][1] = cell_pos_y+1;

                cell[3][0] = cell_pos_x+4;
                cell[3][1] = cell_pos_y+1;
                break;

            case 5: //lighting-mirror
                //root part
                cell[0][0] = cell_pos_x+3;
                cell[0][1] = cell_pos_y;

                cell[1][0] = cell_pos_x+4;
                cell[1][1] = cell_pos_y;

                cell[2][0] = cell_pos_x+4;
                cell[2][1] = cell_pos_y+1;

                cell[3][0] = cell_pos_x+5;
                cell[3][1] = cell_pos_y+1;
                break;
            
            case 6: //l-shape-normal
                //root part
                cell[0][0] = cell_pos_x+3;
                cell[0][1] = cell_pos_y;

                cell[1][0] = cell_pos_x+4;
                cell[1][1] = cell_pos_y;

                cell[2][0] = cell_pos_x+5;
                cell[2][1] = cell_pos_y;

                cell[3][0] = cell_pos_x+5;
                cell[3][1] = cell_pos_y+1;
                break;

            case 7: //l-shape-mirror
                //root part
                cell[0][0] = cell_pos_x+3;
                cell[0][1] = cell_pos_y;

                cell[1][0] = cell_pos_x+3;
                cell[1][1] = cell_pos_y+1;

                cell[2][0] = cell_pos_x+5;
                cell[2][1] = cell_pos_y;

                cell[3][0] = cell_pos_x+5;
                cell[3][1] = cell_pos_y;
                break;
        }
        figureShape = figure_id;
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