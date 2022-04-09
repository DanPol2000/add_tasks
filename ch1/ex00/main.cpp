#include "main.h"

int	main() {
	Zombie *	zombie = newZombie("Ivan");
	zombie->announce();
	delete zombie;

	randomChump("Rasputin");

	return 0;
}