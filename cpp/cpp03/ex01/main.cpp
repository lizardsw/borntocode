#include "ScavTrap.hpp"
#include "ClapTrap.hpp"


int main()
{
	ScavTrap A;
	ScavTrap C("scav_C");
	ScavTrap D("Scav_D");

	std::cout << "------------------------"<< std::endl;
	C.attack("scav_D");
	D.takeDamage(20);
	C.attack("scav_D");
	D.takeDamage(20);
	D.beRepaired(30);

	std::cout << "------------------------"<< std::endl;
	C.attack("scav_D");
	D.takeDamage(20);
	C.attack("scav_D");
	D.takeDamage(20);
	C.attack("scav_D");
	D.takeDamage(20);
	C.attack("scav_D");
	D.takeDamage(20);
	C.attack("scav_D");
	D.takeDamage(20);
	C.attack("scav_D");
	D.takeDamage(20);
	std::cout << "------------------------"<< std::endl;
	C.guardGate();
	std::cout << "------------------------"<< std::endl;

	return 0;
}