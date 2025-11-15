#include "physics.h"

typedef struct ZombieStruct {
    char damage;
} Zombie;

void deal_damage();
char choose_move(HMRCEmployee *hmrc, Player *player);
