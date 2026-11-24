#include <fstream>
#include "file.hpp"

int main(int ac, char **av) {

	//check if input is valid
	if (ac != 4)
		return 1;

	//create vars
	char *filename = av[1];
	char *old_s = av[2];
	char *new_s = av[3];

	//init input and outputfile, also line buffer
	std::ofstream outfile("outfile");
	std::ifstream infile(filename);
	File file;

	//read entire file
	file.read(infile);
	file.replace(old_s, new_s);
	outfile << file.get();

	//close files
	infile.close();
	outfile.close();
}
