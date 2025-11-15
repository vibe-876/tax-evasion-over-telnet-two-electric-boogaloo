typedef struct WeaponStruct {
    char *name;
    char damage;
    char fire_rate;
} Weapon;

typedef struct WeaponCollectionStruct {
  Weapon *weapons;
  int weapon_count;
} WeaponCollection;


Weapon generateWeapon(WeaponCollection *weapon);
void incrementWeaponCount();
void getWeapons(Weapon *weapons);
void makeWeapon(char *name, char damage, char fire_rate);
void add_new_weapon(Weapon w, WeaponCollection *weapons);
void free_room(WeaponCollection *weapons);
