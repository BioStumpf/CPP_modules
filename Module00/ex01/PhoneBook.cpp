#include "PhoneBook.hpp"
#include <iostream>

//contructors
PhoneBook::PhoneBook() : _contacts(0), _oldest(0) {}
PhoneBook::~PhoneBook() {}

bool PhoneBook::prompt(const char *text, std::string &line) {
	while (true) {
		std::cout << text << std::flush;
		if (!std::getline(std::cin, line))
			return (false);
		if (!line.empty())
			return (true);
	}
}

bool PhoneBook::add() {
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
	_phone_book[_oldest].fill(contact);
	_oldest = (_oldest == MAX_CONTACTS) ? 0 : _oldest + 1;
	_contacts = (_contacts == MAX_CONTACTS) ? MAX_CONTACTS : _contacts + 1;
	return (true);
}

void PhoneBook::peek() const {
	for (size_t i = 0; i < _contacts; ++i) {
		_phone_book[i].peek(i);
	}
}

bool PhoneBook::search() {
	std::string line;

	peek();
	if (!prompt("Select a contact: ", line))
		return false;
	if (line.length() != 1
		|| !std::isdigit(static_cast<unsigned char>(line[0]))
		|| (line[0] - '0') >= static_cast<int>(_contacts)) {
		std::cout << "Invalid Index." << std::endl;
		return true;
	}
	_phone_book[line[0] - '0'].display();
	return true;
}
