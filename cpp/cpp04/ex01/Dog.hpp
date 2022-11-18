#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(const Dog &copy);
		Dog(const Brain &brain);
		Dog &operator=(const Dog &copy);
		virtual ~Dog();
		virtual void makeSound() const;
		void showBrain();
		Brain *getBrain();
};

#endif