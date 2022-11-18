#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->name = "default name";
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap " << name << " default constructor" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "FragTrap " << name << " argument constructor!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
{
	this->name = copy.name;
	this->hit_points = copy.hit_points;
	this->energy_points = copy.energy_points;
	this->attack_damage = copy.attack_damage;
	std::cout << "FragTrap " << name << " copy constructor!" << std::endl;\
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	if (this != &copy)
	{
		this->name = copy.name;
		this->hit_points = copy.hit_points;
		this->energy_points = copy.energy_points;
		this->attack_damage = copy.attack_damage; 
	}
	std::cout << "FragTrap " << name << " copy assignmet operator" << std::endl;
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << name << " destructor" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (this->hit_points == 0)
		std::cout << "ScavTrap " << name << " can't move..." << std::endl; 
	else
		std::cout << "ScavTrap " << name << " highFivesGuys!!!!!" << std::endl;
}
