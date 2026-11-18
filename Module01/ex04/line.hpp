#ifndef LINE
#define LINE

#include <string>

class Line {
	public:
		Line();
		~Line();

		bool read(std::ifstream &file);
		void replace(const std::string &old_s, const std::string &new_s);
	
	private:
		std::string _line;
	
};

#endif
