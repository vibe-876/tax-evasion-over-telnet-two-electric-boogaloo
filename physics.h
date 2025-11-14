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
<<<<<<< HEAD
  char block[MAP_SIZE][MAP_SIZE];
  HMRCEmployee hmrc_zombies[MAX_ZOMBIES];
} Map;

Map new_map();

=======
  char block[1024];
  HMRCEmployee hmrc_zombies[21];
} Map;

void tick(Map *map);
>>>>>>> 87504ee (Added some stuff to physics.)
void move_player(Player *player);
void move_hmrc(HMRCEmployee hmrc);
