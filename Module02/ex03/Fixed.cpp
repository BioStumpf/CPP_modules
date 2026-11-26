#include "Fixed.hpp"
#include <iostream>
#include <cmath>

//constant fraction
const int Fixed::_fraction = 8;

//default constructor
Fixed::Fixed() : _value(0) {
};

//integer constructor
//we shift to the left by 8 == *2^8
Fixed::Fixed(const int num) : _value(num << _fraction) {
}

//float constructor
//why not shift by 8 bits (fraction) to the left like with int?
//cause floats are represented differently. so instead, we multiply by:
//2^_fraction == 2^8 and then convert to an integer.
//rounding is just to choose the best possible precision, cause multiplying
//a float may give us another float
Fixed::Fixed(const float num) : _value(roundf(num * (1 << _fraction))) {
}

//copy constructor, though i would prefer a list initialization
Fixed::Fixed(const Fixed &other) : _value(other.getRawBits()){
}

//copy assignment operator
//fixed.operator=(other) == fixed = other;
Fixed& Fixed::operator=(const Fixed &other) {
	setRawBits(other.getRawBits());
	return *this;
}

//destructor
Fixed::~Fixed() {
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

//oparators/overloads
bool Fixed::operator<(const Fixed &other) const {
	return _value < other._value;
}

bool Fixed::operator<=(const Fixed &other) const {
	return _value <= other._value;
}

bool Fixed::operator>(const Fixed &other) const {
	return _value > other._value;
}

bool Fixed::operator>=(const Fixed &other) const {
	return _value >= other._value;
}

bool Fixed::operator==(const Fixed &other) const {
	return _value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const {
	return _value != other._value;
}

//for addition we want: (a/x + b/x) * x
//that becomes: ax/x + bx/x
//which is: a + b --> we can just add the raw values
Fixed Fixed::operator+(const Fixed &other) const {
	Fixed res;

	res.setRawBits(getRawBits() + other.getRawBits());
	return res;
}

//same for subraction
Fixed Fixed::operator-(const Fixed &other) const {
	Fixed res;

	res.setRawBits(getRawBits() - other.getRawBits());
	return res;
}

//we want: (a/x * b/x) * x
//which is: a/x * b/x * x
//which is: a*b*x / x^2
//which is: a*b / x
Fixed Fixed::operator*(const Fixed &other) const {
	Fixed res;

	res.setRawBits(
			(static_cast<long long>(getRawBits()) * other.getRawBits()) / ( 1 << _fraction)
			);
	return res;
}

//we want: (a/x / b/x) * x
//which is: a/x * x/b * x
//which is: a*x/b
Fixed Fixed::operator/(const Fixed &other) const {
	Fixed res;

	res.setRawBits(
			(static_cast<long long>(getRawBits()) * (1 << _fraction) / other.getRawBits())
			);
	return res;
}

Fixed &Fixed::operator++() {
	_value++;
	return *this;
}

Fixed &Fixed::operator--() {
	_value--;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);

	++(*this);
	return tmp;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);

	--(*this);
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return a;
	return b;
}

Fixed const &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return a;
	return b;
}

Fixed const &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a > b)
		return a;
	return b;
}

///////////////
//non member functions/ friend functions
///////////////
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}
