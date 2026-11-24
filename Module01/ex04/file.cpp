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
	size_t start = 0;
	size_t pos;

	if (old_s.length() == 0)
		return ;
	while ((pos = _buf.find(old_s, start)) != _buf.npos) {
		_buf.erase(pos, old_s.length());
		_buf.insert(pos, new_s);
		start += new_s.length();
	}
}
