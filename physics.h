typedef enum WeaponEnum {
  axe,
  moist_nugget,
  blunderbuss
} Weapon;

typedef struct BlockStruct {
  char x;
  char y;
} Block;

typedef struct HMRCEmployeeStruct {
  char x;
  char y;
  char damage;
  char health;
} HMRCEmployee;

typedef struct PlayerStruct {
  char x;
  char y;
  Weapon weapon;
} Player;

typedef struct MapStruct {
  char block[1024];
  unsigned char max_hmrc;
  HMRCEmployee hmrc_zombies[21];
} Map;

void move_player(Player *player);
