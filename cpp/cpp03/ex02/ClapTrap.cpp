#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	this->name = "default name";
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	std::cout << "ClapTrap " << this->name << " default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name):name(name)
{
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	std::cout << "ClapTrap " << name << " argument constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	this->name = copy.name;
	this->hit_points = copy.hit_points;
	this->energy_points = copy.energy_points;
	this->attack_damage = copy.attack_damage;	
	std::cout << "ClapTrap " << this->name << " copy constructor" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	if (this != &copy)
	{
		this->name = copy.name;
		this->hit_points = copy.hit_points;
		this->energy_points = copy.energy_points;
		this->attack_damage = copy.attack_damage;	
	}
	std::cout << "ClapTrap " << name << " copy assignment operator" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << name << " destructor" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->energy_points == 0 || this->hit_points == 0)
	{
		std::cout << "ClapTrap " << this->name << " can't move....." << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target \
			<< ", causing " << this->attack_damage << " points of damage!"<< std::endl;
		this->energy_points--; 
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points < amount)
		this->hit_points = 0;
	else
		this->hit_points -= amount;
	std::cout << "ClapTrap " << this->name << " takeDamage " << amount << std::endl;
	if (this->hit_points == 0)
		std::cout << "ClapTrap " << this->name << " 0 hp..... died" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points == 0 || this->hit_points == 0)
		std::cout << "ClapTrap " << this->name << " can't move...." << std::endl;
	else
	{
		this->hit_points += amount;
		this->energy_points--;
		std::cout << "ClapTrap " << this->name << " beRepaired " << amount \
			<< ", now hit_points " << this->hit_points << std::endl;
	}
}