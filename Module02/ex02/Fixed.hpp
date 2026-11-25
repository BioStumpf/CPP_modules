#ifndef FIXED
#define FIXED

#include <ostream>

class Fixed {
	public:
		//constructors + copy assignment operator
		Fixed();
		Fixed(const int val);
		Fixed(const float val);
		Fixed(const Fixed &other); 
		Fixed& operator=(const Fixed &other);
		//destructor
		~Fixed();

		//member functions
		//accessors
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat(void) const;
		int toInt(void) const;

		//comparison
		bool operator<(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator>(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		//arithmetic
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
		//increment/decrement
		//pre
		Fixed &operator++();
		Fixed &operator--();
		// post --> why the argument? -> this is defined in the language
		Fixed operator++(int);
		Fixed operator--(int);

		//static member functions
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);

		//non members
		//overloaded <<
		//note: if i do:
		//ostream &operator<<(ostream &out);
		//this means we could call the function like:
		//Fixed_obj.operator<<(std::cout);
		//which equals:
		//Fixed << std::cout;
		//a friend function means, its a normal function,
		//not belonging to the class itself, but it gets access
		//to all the private and protected memebers of the class.
		//so you'd call it like:
		//operator<<(std::cout, fixed_obj);
		friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
	
	private:
		int _value;
		static const int _fraction;
};

#endif
