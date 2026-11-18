#ifndef WEAPON
#define WEAPON

#include <string>

class Weapon {
	public:
		//constructor/destructor
		Weapon();
		Weapon(std::string type);
		~Weapon();
	
		//setter and getter
		std::string const &getType() const;
		void setType(std::string type);

	private:
		std::string _type;
		
};

#endif // !WEAPON
