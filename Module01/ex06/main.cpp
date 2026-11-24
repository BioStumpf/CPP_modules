#include "Harl.hpp"

int main(int ac, char **av) {
	Harl harl;
	std::string level;

	if (ac != 2)
		return 1;
	level = av[1];
	harl.filter(level);
	return 0;
}
