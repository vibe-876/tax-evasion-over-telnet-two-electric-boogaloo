#include "physics.h"
#include "queue.h"


void tick(Map *map) {
  return;
}

void player_action(Player *player, Queue *action_queue) {
  return;
}

Map new_map() {
  Map map;
  for(int i = 0; i < MAP_SIZE; i++)
    for(int j = 0; j < MAP_SIZE; j++)
      map.block[i][j] = 0;

  return(map);
}
