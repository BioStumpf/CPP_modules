#include "ClapTrap.hpp"
#include <limits>

int main() {
	ClapTrap a("CA");
	ClapTrap b(a);
	ClapTrap c;
	c = a;

	//show that attack is limited to 10
	for (int i = 0; i < 10; i++) 
		a.attack("some other ClapTrap");
	a.attack("some other ClapTrap");


	//show taking damage is limited to 10 and we can restore at most uint max
	b.takeDamage(10);
	b.takeDamage(1);
	b.beRepaired(std::numeric_limits<unsigned int>::max());
	b.beRepaired(std::numeric_limits<unsigned int>::max());
	b.takeDamage(1);
	b.beRepaired(2);

	//ow that copy assigning worked and that repairing can be done 10 times only
	for (int i = 0; i < 10; i++)
		c.beRepaired(1);
	c.beRepaired(1);

	return 0;
}
