#include "Contact.hpp"
#include <iostream>
#include <iomanip>

//constructors
Contact::Contact() {}
Contact::~Contact() {}

//adding a contact
void Contact::fill(ContactData const &data) 
{
	this->_data = data;
}

void Contact::display() const
{
	std::cout
		<< _data.first_name << '\n' 
		<< _data.last_name << '\n'
		<< _data.nickname << '\n'
		<< _data.phone_number << '\n'
		<< _data.darkest_secret
		<< std::endl;
}

std::string Contact::truncate(std::string const &str)
{
	if (str.length() > PADDING)
		return str.substr(0, PADDING - 1) + '.';
	return str;
}

void Contact::peek(size_t idx) const
{
	std::cout
		<< std::setw(10) << idx << '|' 
		<< std::setw(10) << truncate(_data.first_name) << '|' 
		<< std::setw(10) << truncate(_data.last_name) << '|'
		<< std::setw(10) << truncate(_data.nickname)
		<< std::endl;
}
