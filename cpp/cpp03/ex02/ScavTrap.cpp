#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->name = "default name";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap " << name << " default constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap " << name << " argument constructor!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
	this->name = copy.name;
	this->hit_points = copy.hit_points;
	this->energy_points = copy.energy_points;
	this->attack_damage = copy.attack_damage;
	std::cout << "ScavTrap " << name << " copy constructor!" << std::endl;\
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	if (this != &copy)
	{
		this->name = copy.name;
		this->hit_points = copy.hit_points;
		this->energy_points = copy.energy_points;
		this->attack_damage = copy.attack_damage; 
	}
	std::cout << "ScavTrap " << name << " copy assignmet operator" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << name << " destructor" << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (this->hit_points == 0)
		std::cout << "ScavTrap " << name << " can't move..." << std::endl; 
	else
		std::cout << "ScavTrap " << name << " guard gate ON......" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->energy_points == 0 || this->hit_points == 0)
		std::cout << "ScavTrap " << this->name << " can't move....." << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target \
			<< ", causing " << this->attack_damage << " points of damage!"<< std::endl;
		this->energy_points--; 
	}
}
