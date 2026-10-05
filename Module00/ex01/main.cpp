#include "Contact.hpp"
#include "PhoneBook.hpp"

#include <iostream>
#include <string>

static bool	prompt(const char *text, std::string &line) {
	std::cout << text << std::endl;
	if (!std::getline(std::cin, line))
		return (false);
	return (true);
}

static bool add_contact(PhoneBook &book) {
	t_ContactData contact;

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

int main(void) {
	PhoneBook book;
	std::string line;

	while (true) {
		if (!prompt("Enter a command (ADD; SEARCH; EXIT)", line))
			break ;
		else if (line == "EXIT")
			break ;
		else if (line == "ADD")
			if (!add_contact(book))
				break ;
		book.show();
		// else if (line == "SEARCH")
		// 	search_contact(book);
	}
	return 0;
}
