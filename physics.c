#include "physics.h"
#include <stdlib.h>


void tick(State *state) {
  player_action(state);  
}

void player_action(State *state) {
  Action next_action = dequeue(&state->player.action_queue);
  
  switch(next_action.action_enum) {
  case move:
    player_move(state, next_action);
    break;

  case attack:
    player_attack(state, next_action);
    break;

  case none:
    break;
  }
}

void player_move(State *state, Action next_action) {
  /* We also assume that the only thing you can move through
   * is represented by a space character (0x5f).
   */
  if(state->map.block[state->player.x + next_action.action_union.move[0]][state->player.y + next_action.action_union.move[1]] != ' ') return;
  state->player.x += 1;
}

void player_attack(State *state, Action next_action) {
  switch(state->player.weapon.name[0]) {
  case 'a':
    attack_hmrc_at_coord(state,
			 state->player.x + state->player.direction[0],
			 state->player.y + state->player.direction[1],
			 state->player.weapon);
    break;
  case 'm':
    break;
  case 'b':
    break;
  case 'h':
    break;
  case 'k':
    break;
  default:
    int *px = 0x0;
    int x = 1;
    x += *px;
  }

  return;
}

void attack_hmrc_at_coord(State *state, unsigned char x, unsigned char y, Weapon weapon) {
  if(hmrc_at_coord(state, x, y)) {
    
  }
}
  
char hmrc_at_coord(State *state, unsigned char x, unsigned char y) {
  for(int i = 0; i < state->hmrcs.index; i++)
    if(state->hmrcs.hmrc_employees[i].x == x && state->hmrcs.hmrc_employees[i].y == y)
      return(1);
  return(0);
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
