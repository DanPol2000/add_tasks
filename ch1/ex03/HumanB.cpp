#include "HumanB.h"

HumanB::HumanB(std::string const & new_name) : name(new_name) {
	this->weapon = nullptr;
}

HumanB::HumanB(HumanB const & human_b) {
	*this = human_b;
}

HumanB::~HumanB() {
}

HumanB &	HumanB::operator=(HumanB const & human_b) {
	this->name = human_b.name;
	this->weapon = human_b.weapon;
	return *this;
}

void	HumanB::setWeapon(Weapon & new_weapon) {
	this->weapon = &new_weapon;
}

void	HumanB::attack() {
	std::cout << this->name << " attacks with their "
	<< this->weapon->getType() << std::endl;
}

HumanB::HumanB() {
}