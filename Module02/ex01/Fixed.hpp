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
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat(void) const;
		int toInt(void) const;

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
