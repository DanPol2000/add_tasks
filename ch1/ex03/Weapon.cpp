#include "Weapon.h"

Weapon::Weapon(std::string const & new_type) : type(new_type) {
}

Weapon::Weapon(Weapon const & weapon) {
	*this = weapon;
}

Weapon::~Weapon() {
}

Weapon &	Weapon::operator=(Weapon const & weapon) {
	this->type = weapon.type;
	return *this;
}

std::string const &	Weapon::getType() const {
	return this->type;
}

void	Weapon::setType(std::string const & new_type) {
	this->type = new_type;
}

Weapon::Weapon() {
}