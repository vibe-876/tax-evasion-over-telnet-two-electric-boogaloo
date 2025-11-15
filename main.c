#include <stdio.h>
#include "main.h"
#include "physics.h"
#include "weapons.h"

int main(){
  makeWeapon("axe", '10', '1');
  getWeapons();
  return 0;
}