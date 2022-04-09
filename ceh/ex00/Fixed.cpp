//
// Created by Waif Jonathon on 4/8/22.
//

#include "Fixed.hpp"

Fixed::Fixed() : fixPnt(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &objRef) {
	std::cout << "Copy constructor called" << std::endl;
	*this = objRef;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed& obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixPnt = obj.getRawBits();
	return (*this);
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixPnt);
}

void	Fixed::setRawBits(int const raw) {
	this->fixPnt = raw;
}
