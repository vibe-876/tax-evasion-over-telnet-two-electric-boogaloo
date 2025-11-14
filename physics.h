#define MAP_SIZE 32
#define MAX_ZOMBIES 21

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
  char block[MAP_SIZE][MAP_SIZE];
  HMRCEmployee hmrc_zombies[MAX_ZOMBIES];
} Map;


Map new_map();
void tick(Map *map);
void move_player(Player *player);
void move_hmrc(HMRCEmployee hmrc);
