#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
	FragTrap A;
	FragTrap C("frag_C");
	FragTrap D("frag_D");

	std::cout << "------------------------"<< std::endl;
	C.attack("frag_D");
	D.takeDamage(20);
	C.attack("frag_D");
	D.takeDamage(20);
	D.beRepaired(30);

	std::cout << "------------------------"<< std::endl;
	C.attack("frag_D");
	D.takeDamage(20);
	C.attack("frag_D");
	D.takeDamage(20);
	C.attack("frag_D");
	D.takeDamage(20);
	C.attack("frag_D");
	D.takeDamage(20);
	C.attack("frag_D");
	D.takeDamage(20);
	C.attack("frag_D");
	D.takeDamage(20);
	std::cout << "------------------------"<< std::endl;
	C.highFivesGuys();
	std::cout << "------------------------"<< std::endl;

	return 0;
}