typedef struct MapStruct {
  char block[1024];
  unsigned char max_zombies;
  unsigned char no_zombies;
} Map;

typedef struct BlockStruct {
  char x;
  char y;
} Block;

typedef struct HMRCEmployeeStruct {
  int health;
  char x;
  char y;
  char damage;
  char health;
} HMRCEmployee;

typedef struct PlayerStruct {
  char x;
  char y;
  enum Weapon weapon;
} Player;

typedef enum WeaponEnum {
  axe,
  moist_nugget,
  blunderbuss
} Weapon;
