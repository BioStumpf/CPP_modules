#ifndef FIXED
#define FIXED

class Fixed {
	public:
		//constructors + copy assignment operator
		Fixed();
		Fixed(const Fixed &other); 
		Fixed& operator=(const Fixed &other);
		//destructor
		~Fixed();

		//member functions
		int getRawBits( void ) const;
		void setRawBits( int const raw );
	
	private:
		int _value;
		static const int _fraction;
};

#endif
