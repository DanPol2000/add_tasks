#ifndef CPP_MODULE_01_HUMANA_H
#define CPP_MODULE_01_HUMANA_H
#include <iostream>
#include "Weapon.h"

class HumanA {

public:
	HumanA(std::string const & new_name, Weapon & new_weapon);
	HumanA(HumanA const & human_a);
	virtual ~HumanA();
	HumanA &	operator=(HumanA const & human_a);

	void	attack();

private:
	std::string	name;
	Weapon &	weapon;

	HumanA(Weapon & new_weapon);

};


#endif //CPP_MODULE_01_HUMANA_H
