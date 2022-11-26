#include "Base.hpp"

Base::~Base()
{
}

Base *generate(void)
{
	static int seed;
	if (seed == 0)
	{
		seed = 1;
		std::srand((unsigned int)std::time(NULL));
	}
	int temp = std::rand()%3;
	Base *new_ptr;
	if(temp == 0)
	{
		new_ptr = new A;
		std::cout << "generate A class" << std::endl;
	}
	else if (temp == 1)
	{
		new_ptr = new B;
		std::cout << "generate B class" << std::endl;
	}
	else
	{
		new_ptr = new C;
		std::cout << "generate C class" << std::endl;
	}
	return (new_ptr);
}

void identify(Base *p)
{
	if(dynamic_cast<A*>(p))
	{
		std::cout << "it is A ptr" << std::endl;
	}
	else if(dynamic_cast<B*>(p))
	{
		std::cout << "it is B ptr" << std::endl;
	}
	else if(dynamic_cast<C*>(p))
	{
		std::cout << "it is C ptr" << std::endl;
	}
}

void identify(Base &p)
{
	try
	{
		A &cast_A = dynamic_cast<A&>(p);
		std::cout << "it is A ref" << std::endl;
		static_cast<void>(cast_A);
	}
	catch(std::exception &e){}
	try
	{
		B &cast_B = dynamic_cast<B&>(p);
		std::cout << "it is B ref" << std::endl;
		static_cast<void>(cast_B);
	}
	catch(std::exception &e){}
	try
	{
		C &cast_C = dynamic_cast<C&>(p);
		std::cout << "it is C ref" << std::endl;
		static_cast<void>(cast_C);
	}
	catch(std::exception &e){}
}