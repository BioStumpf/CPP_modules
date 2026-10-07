#include "Zombie.hpp"

int main(void) {

	//allocated zombie returned from function
	Zombie *zom_allocate = newZombie("Helmut");
	zom_allocate->announce();
	delete zom_allocate;

	//non allocated zombie
	randomChump("catalania");

}
