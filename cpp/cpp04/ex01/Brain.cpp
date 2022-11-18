#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "🤯Brain default constructor🤯" << std::endl;
}

Brain::~Brain()
{
	std::cout << "🤯Brain destructor🤯" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = copy.ideas[i];
	}
	std::cout << "🤯Brain copy constructor🤯" << std::endl;
}

Brain &Brain::operator=(const Brain &copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < 100; i++)
		{
			ideas[i] = copy.ideas[i];
		}
	}
	std::cout << "🤯Brain copy assignment🤯" << std::endl;
	return (*this);
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index > 99)
		return ("no brain!");
	return (this->ideas[index]);
}

void Brain::setIdea(const std::string idea, int index)
{
	if (index < 0 || index > 99)
		std::cout << "error index" << std::endl;
	else
		this->ideas[index] = idea;
}
