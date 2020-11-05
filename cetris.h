#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;
class Blocks {
    public:
    int cell[4][2];
    int figureShape;
    int StateOfRotation = 0;
    void summonShape(int figure_id,int cell_pos_x,int cell_pos_y){
        switch (figure_id){
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
                cell[0][0] = cell_pos_x+3;
                cell[0][1] = cell_pos_y;

                cell[1][0] = cell_pos_x+4;
                cell[1][1] = cell_pos_y;

                cell[2][0] = cell_pos_x+5;
                cell[2][1] = cell_pos_y;

                //root part
                cell[3][0] = cell_pos_x+4;
                cell[3][1] = cell_pos_y+1;
                break;

            case 4: //lighting-normal
                cell[0][0] = cell_pos_x+4;
                cell[0][1] = cell_pos_y;

                cell[1][0] = cell_pos_x+5;
                cell[1][1] = cell_pos_y;

                //root part
                cell[2][0] = cell_pos_x+3;
                cell[2][1] = cell_pos_y+1;

                cell[3][0] = cell_pos_x+4;
                cell[3][1] = cell_pos_y+1;
                break;

            case 5: //lighting-mirror
                cell[0][0] = cell_pos_x+3;
                cell[0][1] = cell_pos_y;

                cell[1][0] = cell_pos_x+4;
                cell[1][1] = cell_pos_y;

                //root part
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
    
    void moveBlocksH(int direction, int number_of_movements){
        for (int x = 0; x < 4; x++){
            cell[x][0] += direction*number_of_movements;
        }
    }

    void moveBlocksD(){
        for (int x = 0; x < 4; x++){
            cell[x][1] += 1;
        }
    }

    void rotateBlocks(int number_of_rotation){
        int a;

        if (number_of_rotation > 4){
            number_of_rotation %= 4;
        }
        for (int x = 0; x < 4; x++){
            switch (figureShape){
                case 2: //line
                    switch (StateOfRotation){
                        case 0: //inline
                            a = 1;
                            StateOfRotation = 1;
                            break;
                        case 1: //column
                            a = -1;
                            StateOfRotation = 0;
                            break;
                    }
                    for (int x = 3; x >= 0; x--){
                                cell[x][0] += (a*-1)*x;
                                cell[x][1] += a*x;
                            }
                    break;
                case 3: //t
                    switch (number_of_rotation){
                        case 1: //right from root
                            //lewa
                            cell[0][0] = cell[1][0];
                            cell[0][1] = cell[1][1]+1;

                            //prawa
                            cell[2][0] = cell[1][0];
                            cell[2][1] = cell[1][1]-1;

                            //dolny czubek
                            cell[3][0] = cell[1][0]-1;
                            cell[3][1] = cell[1][1];
                            break;

                        case 2: //nose up
                            //lewa
                            cell[0][0] = cell[1][0]-1;
                            cell[0][1] = cell[1][1];

                            //prawa
                            cell[2][0] = cell[1][0]+1;
                            cell[2][1] = cell[1][1];

                            //dolny czubek
                            cell[3][0] = cell[1][0];
                            cell[3][1] = cell[1][1]-1;
                            break;

                        case 3: //left from root
                            //lewa
                            cell[0][0] = cell[1][0];
                            cell[0][1] = cell[1][1]-1;

                            //prawa
                            cell[2][0] = cell[1][0];
                            cell[2][1] = cell[1][1]+1;

                            //dolny czubek
                            cell[3][0] = cell[1][0]+1;
                            cell[3][1] = cell[1][1];
                            break;

                        default:
                            //lewa
                            cell[0][0] = cell[1][0]-1;
                            cell[0][1] = cell[1][1];

                            //prawa
                            cell[2][0] = cell[1][0]+1;
                            cell[2][1] = cell[1][1];

                            //dolny czubek
                            cell[3][0] = cell[1][0];
                            cell[3][1] = cell[1][1]+1;
                            break;
                        
                    }
                    break;
                case 4:
                    if (number_of_rotation > 1){
                        number_of_rotation %= 2;
                    }
                    switch(number_of_rotation){
                        case 1: //right from root
                            //up right
                            cell[1][0] = cell[2][0]-1;
                            cell[1][1] = cell[2][1]+1;

                            //up mid
                            cell[0][0] = cell[2][0]-1;
                            cell[0][1] = cell[2][1];

                            //down left
                            cell[3][0] = cell[2][0];
                            cell[3][1] = cell[2][1]-1;
                            break;

                        default:
                            //up right
                            cell[1][0] = cell[2][0]+1;
                            cell[1][1] = cell[2][1]+1;

                            //up mid
                            cell[0][0] = cell[2][0];
                            cell[0][1] = cell[2][1]+1;

                            //down left
                            cell[3][0] = cell[2][0]-1;
                            cell[3][1] = cell[2][1];
                            break;
                        
                    }
                    break;
                case 5:
                    if (number_of_rotation > 1){
                        number_of_rotation %= 2;
                    }
                    switch(number_of_rotation){
                        case 1: //right from root
                            //up left
                            cell[1][0] = cell[2][0]-1;
                            cell[1][1] = cell[2][1]+1;

                            //up mid
                            cell[0][0] = cell[2][0]-1;
                            cell[0][1] = cell[2][1];

                            //down right
                            cell[3][0] = cell[2][0];
                            cell[3][1] = cell[2][1]+1;
                            break;

                        default:
                            //up left
                            cell[1][0] = cell[2][0]-1;
                            cell[1][1] = cell[2][1]+1;

                            //up mid
                            cell[0][0] = cell[2][0];
                            cell[0][1] = cell[2][1]+1;

                            //down right
                            cell[3][0] = cell[2][0]+1;
                            cell[3][1] = cell[2][1];
                            break;
                        
                    }
                    break;
                case 6:
                    switch(number_of_rotation){
                        case 1: //right from root
                            //right
                            cell[2][0] = cell[1][0];
                            cell[2][1] = cell[1][1];

                            //left
                            cell[0][0] = cell[1][0];
                            cell[0][1] = cell[1][1];

                            //down right
                            cell[3][0] = cell[1][0];
                            cell[3][1] = cell[1][1];
                            break;

                        case 2: //upside down
                            //right
                            cell[2][0] = cell[1][0]-1;
                            cell[2][1] = cell[1][1];

                            //left
                            cell[0][0] = cell[1][0]+1;
                            cell[0][1] = cell[1][1];

                            //down left
                            cell[3][0] = cell[1][0]+1;
                            cell[3][1] = cell[1][1]-1;
                            break;

                        case 3: //left from root
                            //right
                            cell[2][0] = cell[1][0];
                            cell[2][1] = cell[1][1];

                            //left
                            cell[0][0] = cell[1][0];
                            cell[0][1] = cell[1][1];

                            //down left
                            cell[3][0] = cell[1][0];
                            cell[3][1] = cell[1][1];
                            break;

                        default:
                            //right
                            cell[2][0] = cell[1][0]+1;
                            cell[2][1] = cell[1][1];

                            //left
                            cell[0][0] = cell[1][0]-1;
                            cell[0][1] = cell[1][1];

                            //down left
                            cell[3][0] = cell[1][0]-1;
                            cell[3][1] = cell[1][1]+1;
                            break;
                        
                    }
                    break;
                case 7:
                    switch(number_of_rotation){
                        case 1: //right from root
                            //right
                            cell[2][0] = cell[1][0];
                            cell[2][1] = cell[1][1];

                            //left
                            cell[0][0] = cell[1][0];
                            cell[0][1] = cell[1][1];

                            //down right
                            cell[3][0] = cell[1][0];
                            cell[3][1] = cell[1][1];
                            break;

                        case 2: //upside down
                            //right
                            cell[2][0] = cell[1][0]-1;
                            cell[2][1] = cell[1][1];

                            //left
                            cell[0][0] = cell[1][0]+1;
                            cell[0][1] = cell[1][1];

                            //down left
                            cell[3][0] = cell[1][0]+1;
                            cell[3][1] = cell[1][1]-1;
                            break;

                        case 3: //left from root
                            //right
                            cell[2][0] = cell[1][0];
                            cell[2][1] = cell[1][1];

                            //left
                            cell[0][0] = cell[1][0];
                            cell[0][1] = cell[1][1];

                            //down left
                            cell[3][0] = cell[1][0];
                            cell[3][1] = cell[1][1];
                            break;

                        default:
                            //right
                            cell[2][0] = cell[1][0]+1;
                            cell[2][1] = cell[1][1];

                            //left
                            cell[0][0] = cell[1][0]-1;
                            cell[0][1] = cell[1][1];

                            //down left
                            cell[3][0] = cell[1][0]-1;
                            cell[3][1] = cell[1][1]+1;
                            break;
                        
                    }
                    break;

                default:
                    break;
            }
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
        for (int c = 0; c <= 3; c++){
            for (int y = 0; y <= MAP_HEIGHT-1; y++){
                for (int x = 0; x <= MAP_WIDTH-1; x++){
                    if (blocks.cell[c][0] == x && blocks.cell[c][1] == y){
                        map[x][y] = true;
                    }
                }
            }
        }

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
    }
};