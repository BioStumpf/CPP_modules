#include "Contact.hpp"
#include "PhoneBook.hpp"

#include <cctype>
#include <iostream>
#include <string>

static bool	prompt(const char *text, std::string &line) {
	while (true) {
		std::cout << text << std::flush;
		if (!std::getline(std::cin, line))
			return (false);
		if (!line.empty())
			return (true);
	}
}

static bool add_contact(PhoneBook &book) {
	ContactData contact;

	if (!prompt("First name: ", contact.first_name))
		return (false);
	else if (!prompt("Last name: ", contact.last_name))
		return (false);
	else if (!prompt("Nickname: ", contact.nickname))
		return (false);
	else if (!prompt("Phone number: ", contact.phone_number))
		return (false);
	else if (!prompt("Darkest secret: ", contact.darkest_secret))
		return (false);
	book.add(contact);
	return (true);
}

static bool search_contact(PhoneBook &book)
{
	std::string line;

	book.peek();
	if (!prompt("Select a contact: ", line))
		return false;
	if (line.length() != 1 || !std::isdigit(static_cast<unsigned char>(line[0]))) {
		std::cout << "Invalid Index." << std::endl;
		return true;
	}
	book.display(line[0] - '0');
	return true;
}

int main(void) {
	PhoneBook book;
	std::string line;

	while (true) {
		if (!prompt("Enter a command (ADD; SEARCH; EXIT): ", line))
			break ;
		else if (line == "EXIT")
			break ;
		else if (line == "ADD") {
			if (!add_contact(book))
				break ;
		}
		else if (line == "SEARCH") {
			if (!search_contact(book))
				break ;
		}
	}
	return 0;
}
