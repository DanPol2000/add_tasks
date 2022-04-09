//
// Created by Waif Jonathon on 4/8/22.
//

#ifndef CPPMODULES_FIXED_HPP
#define CPPMODULES_FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed &objRef);
	~Fixed();
	Fixed&	operator=(const Fixed &obj);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
private:
	int					fixPnt;
	static const int	fractBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);

#endif //CPPMODULES_FIXED_HPP
