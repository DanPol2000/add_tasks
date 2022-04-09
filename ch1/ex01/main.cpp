#include "main.h"

int	main() {
	Zombie *	zombies = zombieHorde(CPP_MODULE_01_ZOMBIE_COUNT, "Noname");
	for (int i = 0; i < CPP_MODULE_01_ZOMBIE_COUNT; i++) {
		zombies[i].announce();
	}
	delete [] zombies;
	return 0;
}