#include "Contact.hpp"
#include <iostream>
#include <iomanip>

//constructors
// Contact::Contact(std::string const &first_name, std::string const &last_name,
		// std::string const &nickname, std::string const &phone_number,
		// std::string const &darkest_secret)
		// 	: _first_name(first_name), _last_name(last_name), _nickname(nickname),
		// 	_phone_number(phone_number), _darkest_secret(darkest_secret) {}

Contact::Contact() {}

Contact::~Contact() {}

//adding a contact
void Contact::fill(t_ContactData const &data) 
{
	this->_data = data;
}

void Contact::display(size_t idx) const
{
	std::cout
		<< std::setw(10) << idx << '|' 
		<< std::setw(10) << _data.first_name << '|' 
		<< std::setw(10) << _data.last_name << '|'
		<< std::setw(10) << _data.nickname << '|'
		<< std::endl;
}
