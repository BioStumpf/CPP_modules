#include <fstream>
#include "file.hpp"

int main(int ac, char **av) {

	//check if input is valid
	if (ac != 4)
		return 1;

	//init input and outputfile, also line buffer
	std::ofstream outfile("outfile");
	std::ifstream infile(av[1]);
	File file;

	//read entire file
	file.read(infile);
	file.replace(av[2], av[3]);
	outfile << file.get();

	//close files
	infile.close();
	outfile.close();
}
