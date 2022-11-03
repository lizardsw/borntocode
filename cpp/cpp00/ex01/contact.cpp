#include "contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::set_info(int index, std::string buffer[])
{
	this->index = index + 1;
	this->first_name = buffer[0];
	this->last_name = buffer[1];
	this->nickname = buffer[2];
	this->phone_number = buffer[3];
	this->darkest_secret = buffer[4];
}

void Contact::show_info(void)
{
	std::cout << "index :"<< this->index << std::endl\
	<< "first_name :" << this->first_name << std::endl\
	<< "last_name :" << this->last_name << std::endl\
	<< "nick_name :" << this->nickname << std::endl\
	<< "phone_number :" << this->phone_number<< std::endl\
	<< "darkest_secret :" << this->darkest_secret << std::endl;
}

void Contact::display_index(void)
{
	std::cout << std::setw(10) << std::setfill(' ');
	std::cout << this->index;
	std::cout << "|";
}

void Contact::diplay_first_name(void)
{
	display_context(this->first_name);
}

void Contact::diplay_last_name(void)
{
	display_context(this->last_name);
}

void Contact::diplay_nick_name(void)
{
	display_context(this->nickname);
}

void display_context(std::string context)
{
	if (context.length() > 10)
	{
		context.insert(9, ".");
		context.erase(10, context.length());
	}
	std::cout << std::setw(10) << std::setfill(' ');
	std::cout << context;
	std::cout << "|";

}
