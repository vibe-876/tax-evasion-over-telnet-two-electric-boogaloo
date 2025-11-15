typedef struct WeaponStruct {
    char name[16];
    int damage;
    int fire_rate;
} Weapon;

typedef struct WeaponCollectionStruct {
  Weapon *weapons;
  int weapon_count;
} WeaponCollection;

Weapon weapons[5] = {};

Weapon axe;
axe.name = "axe";
axe.damage = 5;
axe.fire_rate = 1;
weapons[0] = axe;

Weapon moist_nugget;
moist_nugget.name = "moist_nugget";
moist_nugget.damage = 50;
moist_nugget.fire_rate = 1;
weaponsg[1] = moist_nugget;

Weapon blunder_buss;
blunder_buss.name = "blunder_buss";
blunder_buss.damage = 80;
blunder_buss.fire_rate = 3;
weapons[2] = blunder_buss;

//Now conceptualise 2 more weapons later xxx