typedef struct WeaponStruct {
    char name[16];
    char damage;
    char fire_rate;
} Weapon;

void init_weapons();
Weapon generate_weapon();
