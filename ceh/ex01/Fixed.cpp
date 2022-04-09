//
// Created by Waif Jonathon on 4/8/22.
//

#include "Fixed.hpp"

Fixed::Fixed() : fixPnt(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	this->fixPnt = num << this->fractBits;
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
	this->fixPnt = roundf(num * (1 << this->fractBits));
}

Fixed::Fixed(const Fixed &objRef) {
	std::cout << "Copy constructor called" << std::endl;
	*this = objRef;
}

Fixed &Fixed::operator=(const Fixed& obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixPnt = obj.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixPnt);
}

void	Fixed::setRawBits(int const raw) {
	this->fixPnt = raw;
}

float Fixed::toFloat(void) const {
	return ((float)(this->fixPnt) / (1 << this->fractBits));
}

int Fixed::toInt() const {
	return ((int)(this->fixPnt >> this->fractBits));
}

std::ostream& operator<<(std::ostream &out, const Fixed &obj) {
	out << obj.toFloat();
	return (out);
}
