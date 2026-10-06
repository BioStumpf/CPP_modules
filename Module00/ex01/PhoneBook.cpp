#include "PhoneBook.hpp"
#include <iostream>

//contructors
PhoneBook::PhoneBook() : _contacts(0), _oldest(0) {}
PhoneBook::~PhoneBook() {}

void PhoneBook::add(ContactData const &contact) {
	if (this->_contacts == MAX_CONTACTS) {
		this->_phone_book[this->_oldest].fill(contact);
		this->_oldest++;
		this->_oldest = (this->_oldest == MAX_CONTACTS) ? 0 : this->_oldest;
	}
	else {
		this->_phone_book[this->_contacts].fill(contact);
		this->_contacts++;
	}
}

void PhoneBook::peek() const {
	for (size_t i = 0; i < _contacts; ++i) {
		_phone_book[i].peek(i);
	}
}

void PhoneBook::display(size_t idx) const {
	if (idx >= this->_contacts) {
		std::cout << "Invalid Index." << std::endl;
		return ;
	}
	this->_phone_book[idx].display();
}
