#include "physics.h"
#include <stdlib.h>


void tick(State *state) {
  return;
}

void player_action(State *state) {
  Action next_action = dequeue(&state->player.action_queue);
  
  switch(next_action.action_enum) {
  case move:
    player_move(state);
    break;

  case attack:
    player_attack(state);
    break;

  case none:
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

/* From here are queue functions. Originally, these were
 * in their own file, but that is causing circular dependencies,
 * so they're here now. There's a cleaner solution, but this
 * is a game jam, so we're not exactly filled of time for that.
 */
Queue *init_queue() {
  Queue *queue = malloc(sizeof *queue);
  queue->tail = 0;
  return(queue);
}

void enqueue(Queue *queue, Action action) {
  if(queue->tail >= MAX_ACTIONS) return;
  queue->queue[queue->tail++] = action;
}

Action dequeue(Queue *queue) {
  if(queue->tail == 0) {
    union ActionUnion empty_action_union;
    empty_action_union.none = 0;
    return((Action) {none, empty_action_union});
  }
  
  return(queue->queue[queue->tail--]);
}
