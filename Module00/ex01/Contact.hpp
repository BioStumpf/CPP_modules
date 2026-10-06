#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

struct ContactData {
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
};

class Contact {
	public:
		//constructor and destructor
		Contact();
		~Contact();

		//print the contact
		void peek(size_t idx) const;
		void display() const;

		//add to a contact
		void fill(ContactData const &data);

	private:
		//data
		static const size_t PADDING = 10;
		ContactData _data;

		//functions
		static std::string	truncate(std::string const &str);
};

#endif // !CONTACT_CPP
