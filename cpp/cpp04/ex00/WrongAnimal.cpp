#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	this->type = "default";
	std::cout << "🦄WrongAnimal constructor🦄" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	if (this != &copy)
	{
		this->type = copy.type;
	}
	std::cout << "🦄WrongAnimal copy constructor🦄" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
	this->type = copy.type;
	std::cout << "🦄WrongAnimal copy assignment🦄" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "🦄WrongAnimal destructor🦄" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "🦄🦄🦄no-type can't makesound!🦄🦄🦄" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}