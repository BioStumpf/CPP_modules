#include "Fixed.hpp"
#include <iostream>
#define MAX ((1u << 31) - 1)


int main( void ) {
	Fixed a;
	Fixed d;
	d.setRawBits(MAX);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const c( Fixed( 200 ) / Fixed( 2 ) );
	Fixed const e (d/2 * 2);
	Fixed const f ((d + 1)/2 * 2);

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
	std::cout << f << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}
