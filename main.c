#include <stdio.h>
#include "main.h"
#include "physics.h"
#include "graphics.h"

#include "weapons.h"
#include "graphics.h"

void on_connect() {

}

void on_disconnect() {

}

void on_recv(char c) { // WARNING THIS RUNS MULTITHREADED PLS NO RAZE CONDITON // WARNING THIS RUNS MULTITHREADED PLS NO RAZE CONDITON // WARNING THIS RUNS MULTITHREADED PLS NO RAZE CONDITON // WARNING THIS RUNS MULTITHREADED PLS NO RAZE CONDITON

}

void on_conn() {

}

void on_disconn() {

}

void on_input(char c) {

}

int main(){
  // Setup
  graphics_init("127.0.0.1", 8080, (EventCallbacks) {on_conn, on_disconn, on_input});
  init_weapons();
  generate_weapon();

  // Mainloop

  // Teardown
  graphics_deinit();
  
  return 0;
}
