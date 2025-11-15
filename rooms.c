#include "physics.h"
#include <stdio.h>

int rooms() {
    Map maps = new_map();
    for(int x = 0; x < 32; x++){
        maps.block[0][x] = '#';
        maps.block[x][0] = '#';
        maps.block[31][x] = '#';
        maps.block[x][31] = '#';
    }

    

    return 0;
}
