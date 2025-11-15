#include "hmrc.h"
#include "physics.h"


/* Might add some "randomness" to this at
 * some point. Also, should probably add some
 * obstacle avoidance.
 */
char choose_move(HMRCEmployee *hmrc, Player *player) {
  char path;

  char path_to_player_x = player->x - hmrc->x;
  char path_to_player_y = player->y - hmrc->y;
  
  return(path_to_player_x > path_to_player_y ?
	 path_to_player_x :
	 path_to_player_y);
}
