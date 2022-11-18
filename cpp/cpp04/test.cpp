#include <iostream>
#include <string>

class my
{
	private:
		std::string *name;
		char *myname;
		int *number;
	public:

		my(std::string &name)
		{
			this->name = &name;
		}
		my(char *myname)
		{
			this->myname = myname;
		}
		my (int *number)
		{
			this->number = number;
		}
		~my()
		{
			delete name;
			std::cout << "my decon!" << std::endl;
		}
};

class you
{
	private:
		std::string *name;
	public:
		you()
		{
			std::cout << "you con!" << std::endl;
		}
		~you()
		{
			std::cout << "you decon!" << std::endl;
		}
};

// void hello(const std::string A[])
// {
// 	for (int i = 0; i < 10; i++)
// 	{
// 		std::cout << A[i] << std::endl;
// 	}
// 	for (int i = 0; i < 10; i++)
// 	{
// 		A[i] = "no";
// 	}

// }



int main()
{
	my A();
	return 0;
}