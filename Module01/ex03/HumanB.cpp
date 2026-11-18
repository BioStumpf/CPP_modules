#include "HumanB.hpp"
#include <iostream>

//with a reference for _weapon, compiler complains here:
// Constructor for 'HumanB' must explicitly initialize the reference member '_weapon' 
HumanB::HumanB(std::string name) : _name(name) {};
HumanB::~HumanB() {};

void HumanB::attack() const {
	std::cout << _name <<
		" attacks with their " <<
		_weapon->getType() <<
		std::endl;
}

void HumanB::setWeapon(const Weapon &weapon) {
	_weapon = &weapon;
}
