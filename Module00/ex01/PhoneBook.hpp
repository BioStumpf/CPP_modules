#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();
	
		//add a contact to the phone book
		bool add();
	
		//add a contact to the phone book
		bool search();

		//static function to prompt for phone book related input
		static bool prompt(const char *text, std::string &line);

	private:
		static const size_t	MAX_CONTACTS = 8;
		size_t _contacts;
		size_t _oldest;
		Contact _phone_book[MAX_CONTACTS];

		//peek each element of the phonebook
		void peek() const;

};

#endif // !PHONEBOOK_HPP
