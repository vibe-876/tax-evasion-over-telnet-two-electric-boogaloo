#include <stdio.h>
#include "main.h"
#include "physics.h"

#include "weapons.h"
#include "graphics.h"

void on_connect() {

}

void on_disconnect() {

}

void on_recv(char c) { // WARNING THIS RUNS MULTITHREADED PLS NO RAZE CONDITON // WARNING THIS RUNS MULTITHREADED PLS NO RAZE CONDITON // WARNING THIS RUNS MULTITHREADED PLS NO RAZE CONDITON // WARNING THIS RUNS MULTITHREADED PLS NO RAZE CONDITON

}

int main(){
  graphics_init("127.0.0.1", 8080, (EventCallbacks){on_connect, on_disconnect, on_recv});
  graphics_reset_cursor();
  graphics_deinit();
  //makeWeapon("axe", '5', '1');
  return 0;
}
