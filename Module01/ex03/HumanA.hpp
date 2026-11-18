#ifndef HUMANA
#define HUMANA

#include "Weapon.hpp"

class HumanA {
	public:
		HumanA(std::string name, Weapon const &weapon);
		~HumanA();
	
		void attack() const;
	
	private:
		std::string _name;
		//use reference, since it cannot be NULL
		//it cannot be reassigned
		//it must hence be initialized
		Weapon const &_weapon;
};

#endif
