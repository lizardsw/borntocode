#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "🐶Dog constructor🐶" << std::endl;
}

Dog::Dog(const Dog &copy)
{
	if (this != &copy)
	{
		this->type = copy.type;
		this->brain = new Brain();
		*(brain) = *(copy.brain);
	}
	std::cout << "🐶Dog copy constructor🐶" << std::endl;
}

Dog::Dog(const Brain &brain)
{
	this->type = "Dog";
	this->brain = new Brain();
	*(this->brain) = brain;
	std::cout << "🐶Dog brain constructor🐶" << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
	this->type = copy.type;
	*(this->brain) = *(copy.brain);
	std::cout << "🐶Dog copy assignment🐶" << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	delete this->brain;
	std::cout << "🐶Dog destructor🐶" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "🐶🐶🐶 bark bark bark 🐶🐶🐶🐶" << std::endl;
}

void Dog::showBrain()
{
	std::cout << "🐶show dog brain🐶" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::cout << i << ":";
		std::cout << this->brain->getIdea(i) << ", ";
	}
	std::cout << std::endl;
}

Brain *Dog::getBrain()
{
	return (this->brain);
}