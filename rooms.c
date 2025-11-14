#include "physics.h"
#include <stdio.h>

int rooms() {

    char chosen_map;
    Map maps = new_map();
    for(int x = 0; x < 32; x++){
        maps.block[0][x] = '#';
        maps.block[x][0] = '#';
        maps.block[31][x] = '#';
        maps.block[x][31] = '#';
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
