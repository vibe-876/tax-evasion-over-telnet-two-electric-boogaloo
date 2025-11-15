#include "weapons.h"

#define MAP_SIZE 32
#define MAX_ZOMBIES 20
#define MAX_ACTIONS 16


enum ActionEnum {
  move,
  attack,
  none
};

union ActionUnion {
  char move[2];
  unsigned char attack;
  char none;
};

typedef struct ActionStruct {
  enum ActionEnum action_enum;
  union ActionUnion action_union;
} Action;

typedef struct QueueStruct {
  Action queue[MAX_ACTIONS];
  unsigned char tail;
} Queue;

typedef struct BlockStruct {
  char x;
  char y;
} Block;

typedef struct HMRCEmployeeStruct {
  char x;
  char y;
} HMRCEmployee;

typedef struct HMRCEmployeesStruct {
  HMRCEmployee hmrc_employees[MAX_ZOMBIES];
  char index;
} HMRCEmployees;

typedef struct PlayerStruct {
  unsigned char x;
  unsigned char y;
  Weapon weapon;
  Queue action_queue;
} Player;

typedef struct MapStruct {
  unsigned char block[MAP_SIZE][MAP_SIZE];
} Map;

typedef struct StateStruct {
  Map map;
  Player player;
  HMRCEmployees hmrcs;
} State;


Map new_map();
void tick(State *state);
void player_action(State *state);
void player_move(State *state, Action next_action);
void player_attack(State *state, Action next_action);
char hmrc_at_coord(State *state, unsigned char x, unsigned char y);
void move_hmrc(HMRCEmployee hmrc);
Queue *init_queue();
void enqueue(Queue *queue, Action action);
Action dequeue(Queue *queue);
