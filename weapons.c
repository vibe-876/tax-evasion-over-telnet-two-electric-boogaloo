//LETS COMP OUR SOCS BABYYYYYYY - Aidan: 23:41

#include "weapons.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int weaponCount = -1;

Weapon generateWeapon(){//Generate random int within weapons size, then return weapons[index]
    srand(time(0));
    int randomWeaponIndex = rand() % weaponCount;
    return weapons[randomWeaponIndex];
}

void addNewWeapon(Weapon w){ //Increment weapons size, and add the new weapons
    weaponCount++;
    weapons[weaponCount] = w; 
}


void getWeapons(){ //Iterate over what stores the weapons and return their
  for(int i = 0; i < weaponCount; i++){
    printf("%s\n%c\n%c", weapons[i].name, weapons[i].damage, weapons[i].fireRate);
  }
}

Weapon w;

void makeWeapon(char *name, char damage, char fireRate) {
  w.name = name;
  w.damage = damage;
  w.fireRate = fireRate;
  addNewWeapon(w);
}