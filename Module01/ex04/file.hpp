#ifndef FILE_HPP
#define FILE_HPP

#include <string>
#include <fstream> 

class File {
	public:
		File();
		~File();

		void read(std::ifstream &file);
		void replace(const std::string &old_s, const std::string &new_s);
		std::string const &get() const;
	
	private:
		std::string _buf;
	
};

#endif
