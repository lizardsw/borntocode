#include "ClapTrap.hpp"

int main()
{
	ClapTrap A;

	ClapTrap B("B");
	ClapTrap C(B);
	A = B;
	ClapTrap D("D");

	std::cout << "--------------------" << std::endl;
	B.attack("D");
	D.takeDamage(0);
	B.attack("D");
	D.takeDamage(0);

	B.takeDamage(10);
	D.beRepaired(20);
	D.takeDamage(10);
	D.takeDamage(10);
	D.takeDamage(10);
	D.takeDamage(10);

	D.beRepaired(10);
	std::cout << "--------------------" << std::endl;
	return 0;
}