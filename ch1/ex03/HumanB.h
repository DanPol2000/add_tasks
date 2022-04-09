#ifndef CPP_MODULE_01_HUMANB_H
#define CPP_MODULE_01_HUMANB_H
#include <iostream>
#include "Weapon.h"

class HumanB {

public:
	HumanB(std::string const & new_name);
	HumanB(HumanB const & human_b);
	virtual ~HumanB();
	HumanB &	operator=(HumanB const & human_b);

	void	setWeapon(Weapon & new_weapon);
	void	attack();

private:
	std::string	name;
	Weapon *	weapon;

	HumanB();

};


#endif //CPP_MODULE_01_HUMANB_H
