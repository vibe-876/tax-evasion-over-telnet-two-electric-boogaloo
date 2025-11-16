#include <stdio.h>
#include "main.h"
#include "physics.h"

Weapon weapons[5];

int main(){
  init_weapons();
  generate_weapon();
  return 0;
}