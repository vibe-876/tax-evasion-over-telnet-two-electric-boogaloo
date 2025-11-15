//LETS COMP OUR SOCS BABYYYYYYY - Aidan: 23:41

#include "weapons.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


/* Generate random int within weapons size,
 * then return the corresponding weapon.
 */
Weapon generate_weapon(WeaponCollection *weapons) {
    srand(time(0));
    int randomWeaponIndex = rand() % weapons->weapon_count;
    return weapons->weapons[randomWeaponIndex];
}

void add_new_weapon(Weapon w, WeaponCollection *weapons) { //Increment weapons size, and add the new weapons
    weapons->weapon_count++;
    weapons->weapons = realloc(weapons->weapons, weapons->weapon_count * sizeof weapons->weapons);
    weapons->weapons[weapons->weapon_count - 1];
}


/* This can probably be replaced by gdb, which is
 * probably a good habbit to get used to.
 */
void print_weapons(WeaponCollection *weapons) {
    for(int i = 0; i < weapons->weapon_count; i++)
        printf("%s\t%d\t%d\n", weapons->weapons[i].name, weapons->weapons[i].damage, weapons->weapons[i].fire_rate);
}


void make_weapon(char *name, char damage, char fire_rate, WeaponCollection *weapons) {
    Weapon w;
    w.name = name;
    w.damage = damage;
    w.fire_rate = fire_rate;
    add_new_weapon(w, weapons);
}

void free_room(WeaponCollection *weapons) {
    free(weapons->weapons);
    weapons->weapon_count = 0;
}
  
