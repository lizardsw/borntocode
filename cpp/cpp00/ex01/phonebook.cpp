#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	this->list_index = 0;
	this->is_full = false;
}

PhoneBook::~PhoneBook()
{
	this->list_index = 0;
}

void PhoneBook::show_all(void)
{
	for (int i = 0; i < 8; i++)
	{
		this->phone_list[i].show_info();
	}
}

std::string cmd_input(std::string prompt)
{
	std::string temp;
	bool		flag = false;
	int			i = 0;
	int			j = 0;

	while (flag == false)
	{
		i = 0;
		j = 0;
		std::cout << prompt << " :";
		std::getline(std::cin, temp);
		while (temp[i] != '\0')
		{
			if (isspace(temp[i]) == false)
				j++;
			i++;
		}
		if (j != 0)
			flag = true;
	}
	return (temp);
}

bool check_digit(std::string phone_number)
{
	int i = 0;

	while (phone_number[i] != '\0')
	{
		if (std::isdigit(phone_number[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

void PhoneBook::add(void)
{
	if (this->list_index == 8)
	{
		if (this->is_full == false)
			this->is_full = true;
		this->list_index = 0;
	}
	this->buffer[0] = cmd_input("first_name");
	this->buffer[1] = cmd_input("last_name");
	this->buffer[2] = cmd_input("nickname");
	this->buffer[3] = cmd_input("phone_number");
	while (check_digit(this->buffer[3]) == false)
	{
		this->buffer[3] = cmd_input("phone_number");
	}
	this->buffer[4] = cmd_input("darkest_secret");
	this->phone_list[list_index].set_info(this->list_index, this->buffer);
	this->list_index++;
}

void PhoneBook::search(void)
{
	int last;

	if (this->is_full == true)
		last = 8;
	else
		last = this->list_index;
	std::cout << std::setfil <<  
	for (int i; i < last; i++)
	{
		

	}
}

