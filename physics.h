#define MAP_SIZE 32
#define MAX_ZOMBIES 20
#define MAX_ACTIONS 16

/* This is only here to throw a compile-time error
 * after merging, to remind us to link up the physics
 * and the weapons.
 */
typedef char Weapon;

typedef enum ActionUnion {
  move,
  attack,
  none
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
  char damage;
  char health;
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
void player_move(State *state);
void player_attack(State *state);
void move_hmrc(HMRCEmployee hmrc);
Queue *init_queue();
void enqueue(Queue *queue, Action action);
Action dequeue(Queue *queue);
