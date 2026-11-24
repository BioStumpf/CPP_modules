#include "Fixed.hpp"
#include <iostream>

const int Fixed::_fraction = 8;
//constructors + copy assignment
Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	_value = other.getRawBits();
	return *this;
}

//destructor
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
};

//member functions
int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
} 

void Fixed::setRawBits( const int raw ) {
	_value = raw;
}
