#include <string>
#include <iostream>

int main() {

	//init string
	std::string str = "HI THIS IS BRAIN";

	//create another pointer to the string
	std::string *stringPTR = &str;

	//create a reference to the string
	std::string &stringREF = str;

	//print 
	//str address
	std::cout << "string address: " << &str << std::endl;
	//ptr
	std::cout << "stringPTR: " << stringPTR << std::endl;
	//ref
	std::cout << "stringREF: " << &stringREF << std::endl;

	//str address
	std::cout << "string: " << str << std::endl;
	//ptr
	std::cout << "stringPTR: " << *stringPTR << std::endl;
	//ref
	std::cout << "stringREF: " << stringREF << std::endl;
}
