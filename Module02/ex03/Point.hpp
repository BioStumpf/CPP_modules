#ifndef POINT
#define POINT

#include "Fixed.hpp"

class Point {
	public:
		//otrhodox cannonical form constructors/operators/destructors
		Point();
		Point(const Point &other);
		Point(const Fixed &x, const Fixed &y);
		Point &operator=(const Point &other);
		~Point();

		//accessors
		//for x
		const Fixed &get_x() const;
		void set_x(const Fixed &x);
		//for y
		const Fixed &get_y() const;
		void set_y(const Fixed &y);

		//subraction
		Point operator-(const Point &other) const;
		//cross product
		Fixed operator^(const Point &other) const;
	
	private:
		Fixed _x;
		Fixed _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
