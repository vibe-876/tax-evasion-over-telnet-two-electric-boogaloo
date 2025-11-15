//LETS COMP OUR SOCS BABYYYYYYY - Aidan: 23:41

#include "weapons.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


/* Generate random int within weapons size,
 * then return the corresponding weapon.
 */

Weapon weapons[5] = {};

Weapon axe;
axe.name = "axe";
axe.damage = "5";
axe.fire_rate = "1";
weapons[0] = axe;


Weapon generate_weapon(Weapon weapon[]) {
    srand(time(0));
    int randomWeaponIndex = rand() % weapon[].length;
    return weaponArray[randomWeaponIndex];
}

/* This can probably be replaced by gdb, which is
 * probably a good habbit to get used to.
 */