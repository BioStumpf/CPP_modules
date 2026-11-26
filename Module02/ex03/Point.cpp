#include "Point.hpp"

//default constructor
Point::Point() : _x(0), _y(0) {}

//fixed point construction
Point::Point(const Fixed &x, const Fixed &y) : _x(x), _y(y) {}

//copy constructor
Point::Point(const Point &other) : _x(other.get_x()), _y(other.get_y()) {}

//destructor
Point::~Point() {}

//copy assignment operator
Point &Point::operator=(const Point &other) {
	set_x(other.get_x());
	set_y(other.get_y());
	return *this;
}

//accessors
//for x
const Fixed &Point::get_x() const {
	return _x;
}

void Point::set_x(const Fixed &x) {
	_x = x;
}
//for y
const Fixed &Point::get_y() const {
	return _y;
}

void Point::set_y(const Fixed &y) {
	_y = y;
}

Point Point::operator-(const Point &other) const {
	return Point(get_x() - other.get_x(),
			get_y() - other.get_y());
}

//cross product for vector A x B = AyBz - AzBy; AzBx - AxBz; AxBy - AyBx
//though since Z = 0 in 2D only AxBy - AyBx matters which is the z component
//and gives us the direction of vector B with respect to A
//counter clockwise = negative
//clockwise = positive
Fixed Point::operator^(const Point &other) const {
	return Fixed( (_x * other._y) - (_y * other._x) );
}
