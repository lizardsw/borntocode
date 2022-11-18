#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "🐱Cat constructor🐱" << std::endl;
}

Cat::Cat(const Cat &copy)
{
	if (this != &copy)
	{
		this->type = copy.type;
		this->brain = new Brain();
		*(this->brain) = *(copy.brain);
	}
	std::cout << "🐱Cat copy constructor🐱" << std::endl;
}

Cat::Cat(const Brain &brain)
{
	this->type = "Dog";
	this->brain = new Brain();
	*(this->brain) = brain;
	std::cout << "🐱Cat brain constructor🐱" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
	this->type = copy.type;
	*(this->brain) = *(copy.brain);
	std::cout << "🐱Cat copy assignment🐱" << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << "🐱Cat destructor🐱" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "🐱🐱🐱 miaw miaw miaw 🐱🐱🐱🐱" << std::endl;
}

void Cat::showBrain()
{
	std::cout << "🐱show Cat brain🐱" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::cout << i << ":";
		std::cout << this->brain->getIdea(i) << ", ";
	}
	std::cout << std::endl;
}

Brain *Cat::getBrain()
{
	return (this->brain);
}