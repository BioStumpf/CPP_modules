#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _contacts(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::add(t_ContactData const &contact) {
	this->_phone_book[this->_contacts].fill(contact);
	if (this->_contacts < LAST)
		this->_contacts++;
}

void PhoneBook::show() const {
	for (size_t i = 0; i < _contacts; ++i) {
		_phone_book[i].display(i);
	}
}
