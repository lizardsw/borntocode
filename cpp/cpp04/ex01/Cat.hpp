#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Cat : public Animal
{
	private:
		Brain *brain;
	public:
		Cat();
		Cat(const Cat &copy);
		Cat(const Brain &brain);
		Cat &operator=(const Cat &copy);
		virtual ~Cat();
		virtual void makeSound() const;
		void showBrain();
		Brain *getBrain();
};

#endif