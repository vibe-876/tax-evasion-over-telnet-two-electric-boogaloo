#include "hmrcZombie.h"
#include <stdio.h>
#include <stdlib.h>

Zombie generate_zombie(){
    Zombie z;
    z.health = 50;
    z.damage = rand() % 21;
    return z;
}

int deal_damage(Zombie z){
    return z.damage;
}