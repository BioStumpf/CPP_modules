#include <fstream>
#include "file.hpp"

int main(int ac, char **av) {

	//check if input is valid
	if (ac != 4)
		return 1;

	//create vars
	File file;
	std::string filename = av[1];
	std::string outfile_name = filename + ".replace";
	char *old_s = av[2];
	char *new_s = av[3];

	//init input and outputfile
	std::ofstream outfile(outfile_name.c_str());
	if (!outfile.is_open())
		return 1;
	std::ifstream infile(filename.c_str());
	if (!infile.is_open())
		return 1;

	//read entire file
	file.read(infile);
	file.replace(old_s, new_s);
	outfile << file.get();
	if (!outfile.good()) {
		infile.close();
		outfile.close();
		return 1;
	}

	//close files
	infile.close();
	outfile.close();
	return 0;
}
