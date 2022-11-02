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
	std::cout << this->index << " "\
	<< this->first_name << " "\
	<< this->last_name << " "\
	<< this->nickname << " "\
	<< this->phone_number<< " "\
	<< this->darkest_secret << std::endl;
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

void Contact::diplay_phone_number(void)
{
	display_context(this->phone_number);
}

void Contact::diplay_darkest_secret(void)
{
	display_context(this->darkest_secret);	
}

void display_context(std::string context)
{
	if (context.length() > 10)
	{
		context.insert(9, ".");
		context.erase(10, context.length());
	}
	std::cout << context;
}
