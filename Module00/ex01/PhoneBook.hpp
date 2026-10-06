#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();
	
	//add a contact to the phone book
	void add(ContactData const &contact);

	//display the entire phonebook
	void peek() const;
	void display(size_t idx) const;

	private:
		static const size_t	MAX_CONTACTS = 8;
		size_t _contacts;
		size_t _oldest;
		Contact _phone_book[MAX_CONTACTS];
};

#endif // !PHONEBOOK_HPP
