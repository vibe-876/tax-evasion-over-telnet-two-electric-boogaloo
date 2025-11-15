//LETS COMP OUR SOCS BABYYYYYYY - Aidan: 23:41

#include "weapons.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>


/* Generate random int within weapons size,
 * then return the corresponding weapon.
 */

static Weapon weapons[5];

/* Weapon axe; */
/* axe.name = "axe"; */
/* axe.damage = "5"; */
/* axe.fire_rate = "1"; */
/* weapons[0] = axe; */


Weapon generate_weapon(Weapon *weapon_array) {
    srand(time(0));
    int random_weapon_index = rand() % sizeof(weapon_array) / sizeof(weapon_array[0]);
    return weapon_array[random_weapon_index];
}

Weapon init_weapons() {
  Weapon axe;
  strcpy(axe.name, "axe");
  axe.damage = 5;
  axe.fire_rate = 1;
  weapons[0] = axe;

  Weapon moist_nugget;
  strcpy(moist_nugget.name, "moist_nugget");
  moist_nugget.damage = 50;
  moist_nugget.fire_rate = 1;
  weapons[1] = moist_nugget;

  Weapon blunder_buss;
  strcpy(blunder_buss.name, "blunder_buss");
  blunder_buss.damage = 80;
  blunder_buss.fire_rate = 3;
  weapons[2] = blunder_buss;

  Weapon hush_puppy;
  strcpy(hush_puppy.name, "hush_puppy");
  hush_puppy.damage = 20;
  hush_puppy.fire_rate = 1;
  weapons[3] = hush_puppy;

  Weapon katana;
  strcpy(katana.name, "katana");
  katana.damage = 100;
  katana.fire_rate = 3;
  weapons[4] = katana;
}
  /* This can probably be replaced by gdb, which is
   * probably a good habbit to get used to.
   */
