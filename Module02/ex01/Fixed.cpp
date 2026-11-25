#include "Fixed.hpp"
#include <iostream>
#include <cmath>

//constant fraction
const int Fixed::_fraction = 8;

//default constructor
Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
};

//integer constructor
//we shift to the left by 8 == *2^8
Fixed::Fixed(const int num) : _value(num << _fraction) {
	std::cout << "Int constructor called" << std::endl;
}

//float constructor
//why not shift by 8 bits (fraction) to the left like with int?
//cause floats are represented differently. so instead, we multiply by:
//2^_fraction == 2^8 and then convert to an integer.
//rounding is just to choose the best possible precision, cause multiplying
//a float may give us another float
Fixed::Fixed(const float num) : _value(roundf(num * (1 << _fraction))) {
	std::cout << "Float constructor called" << std::endl;
}

//copy constructor, though i would prefer a list initialization
Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

//copy assignment operator
//fixed.operator=(other) == fixed = other;
Fixed& Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(other.getRawBits());
	return *this;
}

//destructor
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
};

//member functions
int Fixed::getRawBits( void ) const {
	return _value;
} 

void Fixed::setRawBits( const int raw ) {
	_value = raw;
}

//reverse process to float constructor
float Fixed::toFloat( void ) const {
	return static_cast<float>(_value) / (1 << _fraction);
}

int Fixed::toInt( void ) const {
	return _value >> _fraction;
}

//non member functions/ friend functions
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}
