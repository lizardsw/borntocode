#include "phonebook.hpp"

int main()
{
	PhoneBook mybook;	
	std::string book_ft;

	while(1)
	{
		std::cout << "[[[ADD, SEARCH, EXIT]]]" << std::endl;
		std::getline(std::cin, book_ft);
		if(book_ft.compare("EXIT") == 0)
			mybook.book_exit();
		else if (book_ft.compare("ADD") == 0)
			mybook.add();
		else if (book_ft.compare("SEARCH") == 0)
			mybook.search();			
	}
	return (0);
}