#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "-----------------------------------" << std::endl;
	const Animal* meta = new Animal();
	std::cout << "-----------------------------------" << std::endl;
	const Animal* j = new Dog();
	std::cout << "-----------------------------------" << std::endl;
	const Animal* i = new Cat();
	std::cout << "-----------------------------------" << std::endl;
	std::cout << std::endl;
	
	std::cout << "-----------------------------------" << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "-----------------------------------" << std::endl;
	meta->makeSound(); //will output the cat sound!
	std::cout << "-----------------------------------" << std::endl;
	j->makeSound();
	std::cout << "-----------------------------------" << std::endl;
	i->makeSound();
	std::cout << "-----------------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "-----------------------------------" << std::endl;
	delete meta;
	std::cout << "-----------------------------------" << std::endl;
	delete j;
	std::cout << "-----------------------------------" << std::endl;
	delete i;
	std::cout << "-----------------------------------" << std::endl;

	std::cout << "-----------------------------------" << std::endl;
	const Animal *correct = new Cat;
	std::cout << "-----------------------------------" << std::endl;
	const WrongAnimal *wrong = new WrongCat;
	std::cout << "-----------------------------------" << std::endl;

	std::cout << "-----------------------------------" << std::endl;
	std::cout << correct->getType() << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << wrong->getType() << std::endl;
	std::cout << "-----------------------------------" << std::endl;

	std::cout << "-----------------------------------" << std::endl;
	correct->makeSound();
	std::cout << "-----------------------------------" << std::endl;
	wrong->makeSound();
	std::cout << "-----------------------------------" << std::endl;

	std::cout << "-----------------------------------" << std::endl;
	delete correct;
	std::cout << "-----------------------------------" << std::endl;
	delete wrong;
	std::cout << "-----------------------------------" << std::endl;

	return 0;
}