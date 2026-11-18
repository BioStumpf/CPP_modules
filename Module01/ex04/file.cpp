#include "file.hpp"

File::File() {}
File::~File() {}

std::string const &File::get() const {
	return _buf;
}

void File::read(std::ifstream &file) {
	char c;

	while (file.get(c)) {
		_buf += c;
	}
}

void File::replace(const std::string &old_s, const std::string &new_s) {
	(void)old_s;
	(void)new_s;
	// for (std::string::size_type i = 0; i < _line.length(); i++) {
	// }
}
