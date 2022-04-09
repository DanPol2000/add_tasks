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

	Fixed	operator+(const Fixed &objR);
	Fixed	operator-(const Fixed &objR);
	Fixed	operator*(const Fixed &objR);
	Fixed	operator/(const Fixed &objR);

	bool	operator>(const Fixed &objR) const;
	bool	operator<(const Fixed &objR) const;
	bool	operator>=(const Fixed &objR) const;
	bool	operator<=(const Fixed &objR) const;
	bool	operator==(const Fixed &objR) const;
	bool	operator!=(const Fixed &objR) const;

	Fixed	&operator++();
	Fixed	&operator--();
	Fixed	operator++(int);
	Fixed	operator--(int);

	static Fixed		&min(Fixed &objL, Fixed &objR);
	static const Fixed	&min(const Fixed &objL, const Fixed &objR);
	static Fixed		&max(Fixed &objL, Fixed &objR);
	static const Fixed	&max(const Fixed &objL, const Fixed &objR);

	int		getRawBits() const;
	void	setRawBits(int raw);
	float	toFloat() const;
	int		toInt() const;
private:
	int					fixPnt;
	static const int	fractBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);


#endif //CPPMODULES_FIXED_HPP
