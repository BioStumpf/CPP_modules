#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie {
	public:
		~Zombie();
		Zombie();

		void announce( void ) const;
		void set_name(std::string const &name);
	
	private:
		std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif // !ZOMBIE_HPP
