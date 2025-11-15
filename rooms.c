#include <stdio.h>
#include "rooms.h"
#include "graphics.h"

#define BROWN '#'
#define CHAIR_COLOUR 'C'
#define WHITE 'W'


static int room_number = 0;

int generate_room() {
    char chosen_map;
    Map maps = new_map();

    //create map border
    for(int x = 0; x < 32; x++){
        maps.block[0][x] = WHITE;
        maps.block[x][0] = WHITE;
        maps.block[31][x] = WHITE;
        maps.block[x][31] = WHITE;
    }
    //final boss room
    if(room_number == 5){

        //create pillars
        for(char x = 0; x < 4; x++){
            for(char y = 0; y < 4; y++){
                maps.block[y + 6][x + 3] = BROWN;
                maps.block[y + 15][x + 6] = BROWN;
                maps.block[y + 20][x + 14] = BROWN;
                maps.block[y + 15][x + 22] = BROWN;
                maps.block[y + 6][x + 25] = BROWN;
            }
        }
        //create desk
        for(char x = 0; x < 11; x++){
            for(char y = 0; y < 5; y++){
                maps.block[y + 3][x + 10] = BROWN;
            }
        }maps.block[10][7] = ' ';
         maps.block[21][7] = ' ';
        //create chair
        for(char x = 0; x < 6; x++){
            for(char y = 0; y < 2; y++){
                maps.block[y + 1][x + 13] = CHAIR_COLOUR;
            }
        }
    }
    //spawn room
    else if(room_number == 0){

        open_doors(maps);
        
    }
    //random rooms
    else{
        switch(chosen_map){

            case 0:
                //create obstacles
                for(char x = 0; x < 9; x++){
                    for(char y = 0; y < 13; y++){
                        maps.block[(y % 11) + 4][(x % 4) + 5] = BROWN;
                        maps.block[(y % 13) + 12][(x % 4) + 12] = BROWN;
                        maps.block[(y % 8) + 22][(x % 3) + 5] = BROWN;
                        maps.block[(y % 3) + 28][(x % 5) + 1] = BROWN;
                        maps.block[(y % 3) + 24][(x % 9) + 21] = BROWN;
                        maps.block[(y % 4) + 6][(x % 5) + 19] = BROWN;
                        maps.block[(y % 13) + 6][(x % 4) + 24] = BROWN;
                    }
                }
            break;

            case 1:
                //create obstacles
                for(char x = 0; x < 8; x++){
                    for(char y = 0; y < 13; y++){
                        maps.block[(y % 4) + 5][(x % 7) + 1] = BROWN;
                        maps.block[(y % 6) + 5][(x % 8) + 11] = BROWN;
                        maps.block[(y % 8) + 4][(x % 4) + 12] = BROWN;
                        maps.block[(y % 10) + 16][(x % 4) + 8] = BROWN;
                        maps.block[(y % 4) + 24][(x % 7) + 16] = BROWN;
                        maps.block[(y % 13) + 15][(x % 4) + 23] = BROWN;
                    }
                }
            break;

            case 2:
                //create obstacles
                for(char x = 0; x < 9; x++){
                    for(char y = 0; y < 13; y++){
                        maps.block[(y % 4) + 5][(x % 5) + 1] = BROWN;
                        maps.block[(y % 10) + 5][(x % 4) + 6] = BROWN;
                        maps.block[(y % 8) + 19][(x % 5) + 6] = BROWN;
                        maps.block[(y % 4) + 19][(x % 9) + 11] = BROWN;
                        maps.block[(y % 10) + 10][(x % 3) + 17] = BROWN;
                        maps.block[(y % 4) + 10][(x % 5) + 20] = BROWN;
                        maps.block[(y % 4) + 10][(x % 2) + 29] = BROWN;
                    }
                }
            break;

            case 3:
                //create obstacles
                for(char x = 0; x < 18; x++){
                    for(char y = 0; y < 18; y++){
                        maps.block[(y % 17) + 1][(x % 4) + 13] = BROWN;
                        maps.block[(y % 4) + 10][(x % 6) + 7] = BROWN;
                        maps.block[(y % 8) + 18][(x % 5) + 4] = BROWN;
                        maps.block[(y % 3) + 23][(x % 3) + 9] = BROWN;
                        maps.block[(y % 11) + 14][(x % 4) + 17] = BROWN;
                        maps.block[(y % 5) + 14][(x % 5) + 22] = BROWN;
                        maps.block[(y % 5) + 26][(x % 5) + 26] = BROWN;
                    }
                }
            break;
            
            case 4:
                //create obstacles
                for(char x = 0; x < 9; x++){
                    for(char y = 0; y < 18; y++){
                        maps.block[(y % 4) + 5][(x % 8) + 1] = BROWN;
                        maps.block[(y % 8) + 18][(x % 4) + 4] = BROWN;
                        maps.block[(y % 4) + 22][(x % 13) + 8] = BROWN;
                        maps.block[(y % 5) + 11][(x % 18) + 12] = BROWN;
                        maps.block[(y % 5) + 16][(x % 5) + 26] = BROWN;
                    }
                }
            break;

            case 5:
                //create obstacles
                for(char x = 0; x < 9; x++){
                    for(char y = 0; y < 18; y++){
                        maps.block[(y % 18) + 7][(x % 5) + 7] = BROWN;
                        maps.block[(y % 6) + 14][(x % 8) + 12] = BROWN;
                        maps.block[(y % 6) + 4][(x % 5) + 16] = BROWN;
                        maps.block[(y % 4) + 1][(x % 4) + 27] = BROWN;
                        maps.block[(y % 6) + 14][(x % 6) + 25] = BROWN;
                    }
                }
            break;
            
            case 6:
                //create obstacles
                for(char x = 0; x < 9; x++){
                    for(char y = 0; y < 13; y++){
                        maps.block[(y % 4) + 7][(x % 3) + 1] = BROWN;
                        maps.block[(y % 4) + 7][(x % 5) + 8] = BROWN;
                        maps.block[(y % 22) + 1][(x % 4) + 13] = BROWN;
                        maps.block[(y % 11) + 15][(x % 5) + 4] = BROWN;
                        maps.block[(y % 3) + 28][(x % 4) + 13] = BROWN;
                        maps.block[(y % 4) + 11][(x % 4) + 17] = BROWN;
                        maps.block[(y % 4) + 11][(x % 6) + 25] = BROWN;
                    }
                }
            break;
            
            case 7:
                //create obstacles
                for(char x = 0; x < 9; x++){
                    for(char y = 0; y < 13; y++){
                        maps.block[(y % 9) + 5][(x % 9) + 5] = BROWN;
                        maps.block[(y % 9) + 18][(x % 9) + 18] = BROWN;
                        maps.block[(y % 9) + 18][(x % 9) + 5] = BROWN;
                        maps.block[(y % 9) + 5][(x % 9) + 18] = BROWN;
                        maps.block[(y % 3) + 7][(x % 4) + 27] = BROWN;
                        maps.block[(y % 3) + 21][(x % 4) + 1] = BROWN;
                    }
                }
            break;
        }
    }
    room_number++;
    return 0;   
}

void print_room(){
    Map maps;
    for(int y = 0; y < 32; y++){
        for(int x = 0; x < 32; x++){
            char c = maps.block[y][x];

            switch(c) {
                case '#':
		  printf("%c, %d, %d, %d\n", c, 230, 142, 10);
                    /* graphics_display(c, 230, 142, 10); */
                    break;
                case 'W':
		  printf("%c, %d, %d, %d\n", c, 255, 255, 255);
                    /* graphics_display(c, 255, 255, 255); */
                    break;
                case 'C':
		  printf("%c, %d, %d, %d\n", c, 247, 197, 247);
                    /* graphics_display(c, 247, 197, 247); */
                
            }
        }
        printf("\n");
    }
}

Map new_map() { 
  Map map;
  for(int i = 0; i < MAP_SIZE; i++)
    for(int j = 0; j < MAP_SIZE; j++)
      map.block[i][j] = ' ';
  
  return(map);
}

void open_doors(Map maps){
    maps.block[0][6] = ' ';
    maps.block[0][7] = ' ';
    maps.block[0][8] = ' ';

    maps.block[0][23] = ' ';
    maps.block[0][24] = ' ';
    maps.block[0][25] = ' ';
}
