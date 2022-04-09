//
// Created by Waif Jonathon on 4/8/22.
//

#ifndef CPPMODULES_FIXED_HPP
#define CPPMODULES_FIXED_HPP

#include <iostream>

class Fixed {
public:
	Fixed();
	Fixed(const Fixed &objRef);
	~Fixed();

	Fixed& operator=(const Fixed &obj);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
private:
	int					fixPnt;
	static const int	fractBits = 8;
};


#endif //CPPMODULES_FIXED_HPP
