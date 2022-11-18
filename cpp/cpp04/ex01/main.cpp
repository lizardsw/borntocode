#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	Animal *meta[10];
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			meta[i] = new Cat();
		else
			meta[i] = new Dog();
	}
	for (int i = 0; i < 10; i++)
		delete meta[i];
	std::cout << std::endl;

	Brain my;
	for (int i = 0; i < 100; i++)
	{
		my.setIdea("!", i);
	}

	Dog *dog_A = new Dog(my);
	Dog *dog_B = new Dog(*dog_A);
	Dog *dog_C = new Dog();
	*dog_C = *dog_A; 
	dog_A->showBrain();
	dog_B->showBrain();
	dog_C->showBrain();
	dog_A->getBrain()->setIdea("hello!!!!!!!!", 1);
	dog_A->showBrain();
	dog_B->showBrain();
	dog_C->showBrain();
	delete dog_A;
	delete dog_B;
	delete dog_C;

	Cat *cat_A = new Cat(my);
	Cat *cat_B = new Cat(*cat_A);
	Cat *cat_C = new Cat();
	*cat_C = *cat_A; 
	cat_A->showBrain();
	cat_B->showBrain();
	cat_C->showBrain();
	cat_A->getBrain()->setIdea("hello!!!!!!!!", 1);
	cat_A->showBrain();
	cat_B->showBrain();
	cat_C->showBrain();
	delete cat_A;
	delete cat_B;
	delete cat_C;

	return 0;
}