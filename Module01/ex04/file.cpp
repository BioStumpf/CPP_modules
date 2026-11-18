#include "file.hpp"
#include <fstream> 

File::File() {}
File::~File() {}

std::string const &File::get() const {
	return _line;
}

bool File::read(std::ifstream &file) {
	if (std::getline(file, _line))
		return true;
	return false;
}

void File::replace(const std::string &old_s, const std::string &new_s) {
	(void)old_s;
	(void)new_s;
	// for (std::string::size_type i = 0; i < _line.length(); i++) {
	// }
}
