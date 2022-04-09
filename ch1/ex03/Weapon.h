#ifndef CPP_MODULE_01_WEAPON_H
#define CPP_MODULE_01_WEAPON_H
#include <iostream>

class Weapon {

public:
	Weapon(std::string const & new_type);
	Weapon(Weapon const & weapon);
	virtual ~Weapon();
	Weapon &	operator=(Weapon const & weapon);

	std::string const &	getType() const;
	void	setType(std::string const & new_type);

private:
	std::string	type;

	Weapon();

};

#endif //CPP_MODULE_01_WEAPON_H
