#include "physics.h"
#include <stdio.h>

int rooms() {

    Map maps = new_map(15);
    for(int x = 0; x < 32; x++){
        Map.block[0][x] = '#';
        Map.block[x][0] = '#';
        Map.block[31][x] = '#';
        Map.block[x][31] = '#';
    }

    

    return 0;
}
