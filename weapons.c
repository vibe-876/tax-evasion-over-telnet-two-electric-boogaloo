//LETS COMP OUR SOCS BABYYYYYYY - Aidan: 23:41

#include "weapons.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* Weapon w; */
/* int weaponCount = -1; */

/* Generate random int within weapons size,
 * then return weapons[index]. */
Weapon generate_weapon(WeaponCollection *weapons) {
    srand(time(0));
    int randomWeaponIndex = rand() % weapons->weapon_count;
    return weapons->weapons[randomWeaponIndex];
}

void add_new_weapon(Weapon w, WeaponCollection *weapons) { //Increment weapons size, and add the new weapons
    weapons->weapon_count++;
    weapons->weapons = (Weapon*) realloc(weapons->weapons, weapons->weapon_count);
    weapons->weapons[weapons->weapon_count - 1];
}


/* This can be replaced by gdb, which is probably
 * a good habbit to get used to.
 */
/* void getWeapons(Weapon *weapons){ //Iterate over what stores the weapons and return their */
/*   for(int i = 0; i < weaponCount; i++){ */
/*     printf("%s\n%c\n%c", weapons[i].name, weapons[i].damage, weapons[i].fireRate); */
/*   } */
/* } */

void make_weapon(char *name, char damage, char fire_rate, WeaponCollection *weapons) {
  Weapon w;
  w.name = name;
  w.damage = damage;
  w.fire_rate = fire_rate;
  add_new_weapon(w, weapons);
}
