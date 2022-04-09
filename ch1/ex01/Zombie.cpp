#include "Zombie.h"

Zombie::Zombie(std::string const & new_name) : name(new_name) {
}

Zombie::Zombie(Zombie const & zombie) {
	*this = zombie;
}

Zombie::~Zombie() {
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

void	Zombie::set_name(std::string const & new_name) {
	this->name = new_name;
}

Zombie::Zombie() {
}
