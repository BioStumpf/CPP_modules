#include "line.hpp"
#include <string>
#include <fstream> 

Line::Line() {}
Line::~Line() {}

bool Line::read(std::ifstream &file) {
	if (std::getline(file, _line))
		return true;
	return false;
}

void Line::replace(const std::string &old_s, const std::string &new_s) {
	(void)old_s;
	(void)new_s;
	// for (std::string::size_type i = 0; i < _line.length(); i++) {
	// }
}
