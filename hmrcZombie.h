typedef struct hmrcZombie {
    int health;
    int damage;
} Zombie;

Zombie generate_zombie();
int deal_damage(Zombie z);