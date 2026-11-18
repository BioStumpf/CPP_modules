#include <fstream>
#include "line.hpp"

int main(int ac, char **av) {

	//check if input is valid
	if (ac != 4)
		return 1;

	//init input and outputfile, also line buffer
	std::ofstream outfile("outfile");
	std::ifstream infile(av[1]);
	Line line;

	//iterate through infile and replace str1 with str2
	while (line.read(infile)) {
		line.replace(av[2], av[3]);
	}

	//close files
	infile.close();
	outfile.close();
}
