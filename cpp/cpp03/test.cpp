#include <iostream>
#include <string>


class Person
{
	protected:
		int old;
	public:
		int my_old;
		Person(void)
		{
			std::cout << "Person default constructor!" << std::endl;
			old = 3;
		}
		Person(int number):old(number)
		{
			std::cout << "Person old constructor!" << std::endl;
		}
		virtual ~Person(void)
		{
			std::cout << "Person destructor! "<< std::endl;
		}
		void show_old(void)
		{
			std::cout << "-----------Person old " << this->old << std::endl;
		}
		virtual void hello(void)
		{
			std::cout << "Person hello !!!!" << std::endl;
		}
};


class Student : public Person
{
	private:
		int student_number;
		// int old;
	public:
		Student(void)
		{
			std::cout << "Student default constructor!" << std::endl;
			student_number = 0;
			this->old = 10;
			std::cout << "Person old " << this->old << std::endl;
		}
		Student(int number)
		{
			std::cout << "Student number constructor" << std::endl;
		}
		~Student(void)
		{
			std::cout << "Student desturctor!" << std::endl;
		}
		void show_number(void)
		{

			this->show_old();
			std::cout <<"--- Student number " << this->student_number << std::endl;
			std::cout <<"--- Student old " << this->old << std::endl;
		}
		void hello(void)
		{
			std::cout << "Student hello !!!!" << std::endl;
		}

};

int main()
{
	// Person A;
	// Person B(10);
	// B.show_old();

	// std::cout << "-------------" << std::endl;
	// Student C;
	// Student D(10);
	// C.show_number();
	// D.show_number();
	// std::cout << sizeof(C) << std::endl;
	// std::cout << "-------------" << std::endl;

	Student me;
	Person *m = &me;
	m->hello();
	me.hello();
	return 0;
}