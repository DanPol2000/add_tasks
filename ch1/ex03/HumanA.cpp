#include "HumanA.h"

HumanA::HumanA(std::string const & new_name, Weapon & new_weapon) :
name(new_name), weapon(new_weapon) {
}

HumanA::HumanA(HumanA const & human_a) : weapon(human_a.weapon) {
	*this = human_a;
}

HumanA::~HumanA() {
}

HumanA &	HumanA::operator=(HumanA const & human_a) {
	this->name = human_a.name;
	this->weapon = human_a.weapon;
	return *this;
}

void	HumanA::attack() {
	std::cout << this->name << " attacks with their "
	<< this->weapon.getType() << std::endl;
}

HumanA::HumanA(Weapon & new_weapon) : weapon(new_weapon) {
}