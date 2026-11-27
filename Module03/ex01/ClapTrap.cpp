#include "ClapTrap.hpp"
#include <iostream>
#include <limits>

ClapTrap::ClapTrap() {
	std::cout << "ClapTrap " << "\"unknown\" " << "default constructed." << std::endl;
}
ClapTrap::ClapTrap(const std::string &name)
	: _name(name),
	_hit_points(10),
	_energy_points(10),
	_attack_damage(10) {
	std::cout << "ClapTrap " << _name << " constructed from name." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: _name(other._name),
	_hit_points(other._hit_points),
	_energy_points(other._energy_points),
	_attack_damage(other._attack_damage) {
	std::cout << "ClapTrap " << _name << " copy constructed." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	_name = other._name;
	_hit_points = other._hit_points;
	_energy_points = other._energy_points;
	_attack_damage = other._attack_damage;
	std::cout << "ClapTrap " << _name << " copy assigned." << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destroyed." << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	if (_energy_points == 0 || _hit_points == 0) {
		std::cout
			<< "ClapTrap "
			<< _name
			<< " can't attack right now."
			<< std::endl;
		return ;
	}

	_energy_points--;

	std::cout
		<< "ClapTrap "
		<< _name
		<< " attacks "
		<< target
		<< ", causing "
		<< _attack_damage
		<< " points of damage!"
		<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {

	//check if ClapTrap is dead
	if (_hit_points == 0) {
		std::cout << "ClapTrap " << _name << " is alrady dead." << std::endl;
		return ;
	}

	//check the amount of damage to be dealed
	_hit_points -= (amount > _hit_points) ? _hit_points : amount;

	//print ClapTrap took damage
	std::cout
		<< "ClapTrap "
		<< _name
		<< " took "
		<< amount
		<< " damage. "
		<< _hit_points
		<< " hit points are left."
		<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	const unsigned long max = std::numeric_limits<unsigned int>::max();

	if (_energy_points == 0) {
		std::cout
			<< "ClapTrap "
			<< _name
			<< " is out of energy."
			<< std::endl;
		return ;
	}

	_energy_points--;
	_hit_points = ((max - _hit_points) <= amount) ? max : _hit_points + amount;

	std::cout
		<< "ClapTrap "
		<< _name
		<< " refilled "
		<< amount 
		<< " hit points. "
		<< _hit_points
		<< " hit points are left."
		<< std::endl;
}
