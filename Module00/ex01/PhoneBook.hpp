#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# define SIZE 8
# define LAST 7

#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();
	
	//add a contact to the phone book
	void add(t_ContactData const &contact);

	//display the entire phonebook
	void show() const;

	private:
		size_t _contacts;
		Contact _phone_book[SIZE];
};

#endif // !PHONEBOOK_HPP
