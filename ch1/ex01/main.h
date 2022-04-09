#ifndef CPP_MODULE_01_MAIN_H
#define CPP_MODULE_01_MAIN_H
#include <iostream>
#include "Zombie.h"
#ifndef CPP_MODULE_01_ZOMBIE_COUNT
#define CPP_MODULE_01_ZOMBIE_COUNT 5
#endif

Zombie *	zombieHorde(int N, std::string name);

#endif //CPP_MODULE_01_MAIN_H
