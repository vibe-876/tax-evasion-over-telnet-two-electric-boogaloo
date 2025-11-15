#include "physics.h"
#include <stdio.h>

static int room_number = 0;

int rooms() {
    char chosen_map;
    Map maps = new_map();

    //create map border
    for(int x = 0; x < 32; x++){
        maps.block[0][x] = '#';
        maps.block[x][0] = '#';
        maps.block[31][x] = '#';
        maps.block[x][31] = '#';
    }

    //final boss
    if(room_number == 5){

        maps.block[0][0] = '#';

    }
    //spawn room
    else if(room_number == 0){

        maps.block[0][6] = ' ';
        maps.block[0][7] = ' ';
        maps.block[0][8] = ' ';

        maps.block[0][22] = ' ';
        maps.block[0][23] = ' ';
        maps.block[0][24] = ' ';
        
    }
    //random rooms
    else{
        switch(chosen_map){

            case 1:

                maps.block[0][0] = '#';

            break;

            case 2:

                maps.block[0][0] = '#';

            break;

            case 3:

                maps.block[0][0] = '#';

            break;

            case 4:

                maps.block[0][0] = '#';

            break;
            
            case 5:

                maps.block[0][0] = '#';

            break;

            case 6:

                maps.block[0][0] = '#';

            break;
            
            case 7:

                maps.block[0][0] = '#';

            break;
            
            case 8:

                maps.block[0][0] = '#';

            break;
        }
    }

    return 0;
}


Map new_map() {
  Map map;
  for(int i = 0; i < MAP_SIZE; i++)
    for(int j = 0; j < MAP_SIZE; j++)
      map.block[i][j] = 0;
  
  return(map);
}
