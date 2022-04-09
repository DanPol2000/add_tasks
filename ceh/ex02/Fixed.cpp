//
// Created by Waif Jonathon on 4/8/22.
//

#include "Fixed.hpp"

Fixed::Fixed() : fixPnt(0) {}

Fixed::Fixed(const int num) {
	this->fixPnt = num << this->fractBits;
}

Fixed::Fixed(const float num) {
	this->fixPnt = roundf(num * (1 << this->fractBits));
}

Fixed::Fixed(const Fixed &objRef) {
	*this = objRef;
}

Fixed::~Fixed() {
}

Fixed &Fixed::operator=(const Fixed& obj) {
	this->fixPnt = obj.getRawBits();
	return (*this);
}

Fixed Fixed::operator+(const Fixed& objR) {
	return Fixed(this->toFloat() + objR.toFloat());;
}

Fixed Fixed::operator-(const Fixed& objR) {
	return Fixed(this->toFloat() - objR.toFloat());;
}

Fixed Fixed::operator*(const Fixed& objR) {
	return Fixed(this->toFloat() * objR.toFloat());;
}

Fixed Fixed::operator/(const Fixed& objR) {
	return Fixed(this->toFloat() / objR.toFloat());;
}

bool Fixed::operator>(const Fixed &objR) const {
	return (this->fixPnt > objR.fixPnt);
}

bool Fixed::operator<(const Fixed &objR) const {
	return (this->fixPnt < objR.fixPnt);
}

bool Fixed::operator>=(const Fixed &objR) const {
	return (this->fixPnt >= objR.fixPnt);
}

bool Fixed::operator<=(const Fixed &objR) const {
	return (this->fixPnt <= objR.fixPnt);
}

bool Fixed::operator==(const Fixed &objR) const {
	return (this->fixPnt == objR.fixPnt);
}

bool Fixed::operator!=(const Fixed &objR) const {
	return (this->fixPnt != objR.fixPnt);
}

Fixed &Fixed::operator++(void) {
	this->fixPnt += 1;
	return (*this);
}

Fixed &Fixed::operator--(void) {
	this->fixPnt -= 1;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

Fixed &Fixed::min(Fixed &objL, Fixed &objR) {
	return (objL < objR ? objL : objR);
}

const Fixed &Fixed::min(const Fixed &objL, const Fixed &objR) {
	return (objL < objR ? objL : objR);
}

Fixed &Fixed::max(Fixed &objL, Fixed &objR) {
	return (objL > objR ? objL : objR);
}

const Fixed &Fixed::max(const Fixed &objL, const Fixed &objR) {
	return (objL > objR ? objL : objR);
}

int Fixed::getRawBits() const{
	return (this->fixPnt);
}

void	Fixed::setRawBits(int raw) {
	this->fixPnt = raw;
}

float Fixed::toFloat() const {
	return ((float)(this->fixPnt) / (1 << this->fractBits));
}

int Fixed::toInt() const {
	return ((int)(this->fixPnt >> this->fractBits));
}

std::ostream& operator<<(std::ostream &out, const Fixed &obj) {
	out << obj.toFloat();
	return (out);
}
