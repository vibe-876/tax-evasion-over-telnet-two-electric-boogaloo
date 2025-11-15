# Weapons Docs
The main change is changing `Weapon` to a new struct, `WeaponCollection`.
```C
typedef struct WeaponCollectionStruct {
  Weapon *weapons;
  int weapon_count;
} WeaponCollection;
```
This contains an array of `Weapon`s, which is dynamically allocated as the program is running, and `weapon_count`.
Both of these serve the same purpose that they originally did in the version prior to my commits (commit `64a097471dda166d5251c065428e96fc771c574a`).
I've put them into a struct because that makes them easier to keep constant across the program, and prevent memory related issues.

I've also changed all functions and variables into snake case.
The changes the functions are given below.

- `generate_weapon(WeaponCollection *weapons)`
Still does *basically* the same thing, just with a `WeaponCollection` struct now instead of a `Weapon` struct.

- `add_new_weapon(Weapon w, WeaponCollection *weapons);`
This is doing the same thing that it was previously, but we're explicitly passing the array of `Weapon`s (through the `WeaponCollection` struct), and we're now dynamically allocating memory.

- `print_weapons(WeaponCollection *weapons)`
Replacement for `getWeapons`, I feel like this is a more accurate name, since a getter would return some private (or maybe public I guess) variable, not print it.
It does the same as the original, but with the `WeaponCollection` struct.

- `void make_weapon(char *name, char damage, char fire_rate, WeaponCollection *weapons)`
Still doing the same thing, but (same as `add_new_weapon`) we're now explicitly passing the `WeaponCollection` struct.

- `void free_room(WeaponCollection *weapons);`
Should be called once the room is done with, deallocates all of the weapons that were in memory.
**If this isn't called, there will be a memory leak!**
