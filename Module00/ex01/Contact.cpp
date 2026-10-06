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

static std::string truncate(std::string const &str)
{
	if (str.length() > PAD)
		return str.substr(0, PAD - 1) + '.';
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
