#ifndef CPP_MODULE_01_ZOMBIE_H
#define CPP_MODULE_01_ZOMBIE_H
#include <iostream>

class Zombie {

public:
	Zombie();
	Zombie(std::string const & new_name);
	Zombie(Zombie const & zombie);
	virtual ~Zombie();
	Zombie &	operator=(Zombie const & zombie);

	void	announce();
	void	set_name(std::string const & new_name);

private:
	std::string	name;

};


#endif //CPP_MODULE_01_ZOMBIE_H
