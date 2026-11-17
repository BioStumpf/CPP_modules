#include "Zombie.hpp"
#define N 20

int main(void) {

	//make zombiehorde
	Zombie *horde = zombieHorde(N, "Doofer Zombie");

	//announce the horde
	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}

	//deallocate the horde
	delete[] horde;

}
