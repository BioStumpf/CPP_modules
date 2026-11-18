#ifndef HUMANB
#define HUMANB

#include "Weapon.hpp"

class HumanB {
	public:
		HumanB(std::string name);
		~HumanB();
	
		void attack() const;
		void setWeapon(const Weapon &weapon);
	
	private:
		std::string _name;
		//why a pointer here? -> we cant make it a reference
		//cause a reference has to be initialized, a pointer doesnt
		const Weapon *_weapon;
};

#endif
