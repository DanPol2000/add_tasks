#include "Zombie.h"

Zombie::Zombie(std::string const & new_name) : name(new_name) {
}

Zombie::Zombie(Zombie const & zombie) {
	*this = zombie;
}

Zombie::~Zombie() {
	std::cout << this->name << ": RIP" << std::endl;
}

Zombie &	Zombie::operator=(Zombie const & zombie) {
	if (this != &zombie) {
		this->name = zombie.name;
	}
	return *this;
}

void	Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie() {
}
