#include "queue.h"

#define MAP_SIZE 32
#define MAX_ZOMBIES 20

typedef char Weapon;

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

typedef struct HMRCEmployeesStruct {
  HMRCEmployee hmrc_employees[MAX_ZOMBIES];
  char index;
} HMRCEmployees;

typedef struct PlayerStruct {
  char x;
  char y;
  Weapon weapon;
  Queue action_queue;
} Player;

typedef struct MapStruct {
  char block[MAP_SIZE][MAP_SIZE];
} Map;

typedef struct StateStruct {
  Map map;
  Player player;
  HMRCEmployees hmrcs;
} State;


Map new_map();
void tick(State *state);
void player_action(State *state);
void player_move(State *state);
void player_attack(State *state);
void move_hmrc(HMRCEmployee hmrc);
