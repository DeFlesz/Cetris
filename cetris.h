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

                cell[2][0] = cell_pos_x+4;
                cell[2][1] = cell_pos_y;

                cell[3][0] = cell_pos_x+5;
                cell[3][1] = cell_pos_y;
                break;
        }
        figureShape = figure_id;
    }
    
    void moveBlock(int v, int h){
        for (int x = 0; x < 4; x++){
            cell[x][0] += v;
            cell[x][1] += h;
        }
    }

    void rotateBlock(int number_of_rotation){
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
                            cell[1][0] = cell[2][0]+1;
                            cell[1][1] = cell[2][1]-1;

                            //up mid
                            cell[0][0] = cell[2][0]+1;
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
        int score = 0;

        bool inGame = true;
        char input;
        int rotation = 0;
        bool can_move_down;
        bool can_move_right;
        bool can_move_left;

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
        Cetris::hideCells(can_move_down);

        for (int n = 0; n<4; n++){
            if (blocks.cell[n][1]<MAP_HEIGHT-1 && map[blocks.cell[n][0]][blocks.cell[n][1]+1] == false){
                can_move_down = true;

            } else{
               can_move_down = false;
               rotation = 0;
               break;
            } 
        }

        for (int n = 0; n<4; n++){
            if (blocks.cell[n][1]<MAP_WIDTH-1 && map[blocks.cell[n][0]+1][blocks.cell[n][1]] == false){
                can_move_right = true;
                
            } else{
                can_move_right = false;
                break;
            } 
        }

        for (int n = 0; n<4; n++){
            if (blocks.cell[n][1]>0 && map[blocks.cell[n][0]-1][blocks.cell[n][1]] == false){
                can_move_left = true;
                
            } else{
               can_move_left = false; 
               break;
            } 
        }

        // && map[blocks.cell[n][0]][blocks.cell[n][1]+1] == false
        /*for (int x = 9; x>=0; x--){
            for (int y = 19; y>=0; y--){
                switch(blocks.figureShape){
                    case 1:
                }
            }
        }*/

        //hide

        if (can_move_down==true){
            blocks.moveBlock(0, 1);
        }

        Cetris::scanMap();

        //show
        Cetris::showCells(can_move_down);
        

        if (can_move_down==false){
            srand(time(NULL));
            blocks.summonShape(rand() % 7 + 1, 0, 0);
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
        cout << score;
    }

    void hideCells(bool can_move_down){
        for (int c = 0; c <= 3; c++){
            for (int y = 0; y <= MAP_HEIGHT-1; y++){
                for (int x = 0; x <= MAP_WIDTH-1; x++){
                    if (blocks.cell[c][0] == x && blocks.cell[c][1] == y && can_move_down == true){
                        map[x][y] = false;
                    }
                }
            }
        }
    }

    void showCells(bool can_move_down){
        for (int c = 0; c <= 3; c++){
            for (int y = 0; y <= MAP_HEIGHT-1; y++){
                for (int x = 0; x <= MAP_WIDTH-1; x++){
                    if (blocks.cell[c][0] == x && blocks.cell[c][1] == y){
                        map[x][y] = true;
                    }
                }
            }
        }
    }

    void scanInput(){
        input = getchar();
        Cetris::hideCells(can_move_down);
        if (input == 'd' && can_move_right)
        {
            blocks.moveBlock(1, -1);

        } else if (input == 'a' && can_move_left){
            blocks.moveBlock(-1, -1);

        } else if (input == 'q'){
            rotation--;
            blocks.rotateBlock(rotation);
            blocks.moveBlock(0, -1);

        } else if (input == 'e'){
            rotation++;
            blocks.rotateBlock(rotation);
            blocks.moveBlock(0, -1);
            
        }
    }

    void scanMap(){
        int c;
        for (int y = 19; y>=0; y--){
            for (int x = 9, c = 0; x>=0; x--){
                c++;
            }
            if(c==10){
                for (int x = 9, c = 0; x>=0; x--){
                    score++;
                    map[x][y] = false;
                }
            }
            if (map[4][0] == true && blocks.cell[0][1] != y){
                inGame = false;
            }
        }
    }

    void init(){
        Cetris::createMap();
    }
};