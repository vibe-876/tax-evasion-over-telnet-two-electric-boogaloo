#include "physics.h"
#include "queue.h"


void tick(State *state) {
  return;
}

void player_action(State *state) {
  Action next_action = dequeue(&state->player.action_queue);
  
  switch(next_action) {
  case move:
    player_move(state);
    break;

  case attack:
    player_attack(state);
    break;
  }
}

void player_move(State *state) {
  /* For now, we assume that the direction is /always/ right.
   * We also assume that the only thing you can move through is
   * represented by a space character (0x5f).
   */
  if(state->map.block[state->player.x + 1][state->player.y] == ' ') return;
  state->player.x += 1;
}

void player_attack(State *state) { return; }

Map new_map() {
  Map map;
  for(int i = 0; i < MAP_SIZE; i++)
    for(int j = 0; j < MAP_SIZE; j++)
      map.block[i][j] = 0;

  return(map);
}
