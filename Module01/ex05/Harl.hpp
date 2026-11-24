#ifndef HARL
#define HARL

#include <string>

class Harl;

struct level { 
	std::string name;
	void (Harl::*func)( void );
};

class Harl {
	public:
		Harl();
		~Harl();

		void complain( std::string level );
	
	private:
		//map of function pointers depending on level
		//static cause we dont want a copy for each instance
		//const cause we wont change it
		static const size_t _MAX;
		static const level _LEVELS[4];

		//level functions
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

#endif
