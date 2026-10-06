#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# define MAX 2
# define LAST (MAX - 1)

#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();
	
	//add a contact to the phone book
	void add(t_ContactData const &contact);

	//display the entire phonebook
	void peek() const;
	void display(size_t idx) const;

	private:
		size_t _contacts;
		size_t _oldest;
		Contact _phone_book[MAX];
};

#endif // !PHONEBOOK_HPP
