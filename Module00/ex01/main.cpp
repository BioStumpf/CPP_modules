#include "PhoneBook.hpp"

#include <cctype>
#include <string>

int main(void) {
	PhoneBook book;
	std::string line;

	while (true) {
		if (!PhoneBook::prompt("Enter a command (ADD; SEARCH; EXIT): ", line))
			break ;
		else if (line == "EXIT")
			break ;
		else if (line == "ADD") {
			if (!book.add())
				break ;
		}
		else if (line == "SEARCH") {
			if (!book.search())
				break ;
		}
	}
	return 0;
}
