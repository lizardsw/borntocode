#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
	std::cout << "🦕WrongCat constructor🦕" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	if (this != &copy)
	{
		this->type = copy.type;
	}
	std::cout << "🦕WrongCat copy constructor🦕" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	this->type = copy.type;
	std::cout << "🦕WrongCat copy assignment🦕" << std::endl;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "🦕WrongCat destructor🦕" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "🦕🦕🦕 miaw miaw miaw 🦕🦕🦕🦕" << std::endl;
}
