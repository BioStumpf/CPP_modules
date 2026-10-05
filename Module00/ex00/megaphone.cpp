#include <cctype>
#include <iostream>

static void ft_upper(std::string &str) {
	for (std::string::size_type i = 0; i < str.length(); i++) {
		str[i] = std::toupper(static_cast<unsigned char>(str[i]));
	}
}

int main(int ac, char **av)
{
	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else {
		for (int i = 1; i < ac; i++) {
			std::string str(av[i]);
			ft_upper(str);
			std::cout << str;
		}
		std::cout << std::endl;
	}
	return 0;
}

// static void	ft_upper(char *&str) {
// 	for (char *p = str; *p; ++p) {
// 		*p = std::toupper(*p);
// 	}
// }
//
// int main (void) {	
// 	char *str = (char *)malloc(2);
// 	str[0] = 'h';
// 	str[1] = 'i';
// 	ft_upper(str);
// 	return 0;
// }

// int main(int ac, char **av){
// 	if (ac == 1) {
// 		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
// 	}
// 	else {
// 		for (size_t i = 1; i < ac; ++i) {
// 			ft_upper(av[i]);
// 			std::cout << av[i] << " ";
// 		}
// 		std::cout << std::endl;
// 	}
// 	return 0;
// }
