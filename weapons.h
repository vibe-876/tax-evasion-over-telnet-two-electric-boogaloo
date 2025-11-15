typedef struct WeaponStruct {
    char *name;
    char damage;
    char fireRate;
} Weapon;
Weapon generateWeapon();
void incrementWeaponCount();
void getWeapons();
void makeWeapon(char *name, char damage, char fireRate);
void addNewWeapon(Weapon w);