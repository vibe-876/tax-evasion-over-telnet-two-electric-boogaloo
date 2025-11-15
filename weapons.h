typedef struct WeaponStruct {
    char name[16];
    int damage;
    int fire_rate;
} Weapon;

typedef struct WeaponCollectionStruct {
  Weapon *weapons;
  int weapon_count;
} WeaponCollection;


//Now conceptualise 2 more weapons later xxx
