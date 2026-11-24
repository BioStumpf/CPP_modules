#include <iostream>
#include "Harl.hpp"

Harl::Harl() {};
Harl::~Harl() {};

const size_t Harl::_MAX = 4;

const level Harl::_LEVELS[Harl::_MAX] = {
	{"DEBUG", &Harl::debug},
	{"INFO", &Harl::info},
	{"WARNING", &Harl::warning},
	{"ERROR", &Harl::error}
};

//level functions
void Harl::debug( void ) {
	std::cout << "DEBUGGING" << std::endl;
}

void Harl::info( void ) {
	std::cout << "INFOING" << std::endl;
}

void Harl::warning( void ) {
	std::cout << "WARNING" << std::endl;
}

void Harl::error( void ) {
	std::cout << "ERRORING" << std::endl;
}

size_t Harl::hash( std::string &level ) {
	for (size_t i = 0; i < _MAX; i++)
		if (level == _LEVELS[i].name)
			return i;
	return _MAX;
}

void Harl::filter( std::string &level ) {
	size_t idx = hash(level);

	switch (idx) {
		default:
			std::cout <<
				"[ Probably complaining about insignificant problems ]"
				<< std::endl;
			break ;
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
	}
}
