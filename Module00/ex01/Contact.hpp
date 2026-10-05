#ifndef CONTACT_CPP
# define CONTACT_CPP

#include <string>

typedef struct s_ContactData {
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
}				t_ContactData;

class Contact {
	public:
		//constructor and destructor
		Contact();
		// Contact(std::string const &first_name, std::string const &last_name,
		// 		std::string const &nickname, std::string const &phone_number,
		// 		std::string const &darkest_secret);
		~Contact();

		//print the contact
		void display(size_t idx) const;

		//add to a contact
		void fill(t_ContactData const &data);

	private:
		t_ContactData _data;
};

#endif // !CONTACT_CPP
