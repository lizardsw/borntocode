/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:15:56 by seongwch          #+#    #+#             */
/*   Updated: 2022/11/08 14:16:13 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->list_index = 0;
	this->is_full = false;
}

PhoneBook::~PhoneBook()
{
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
	std::string temp;
	int last;
	int input;

	if (this->is_full == true)
		last = 8;
	else
		last = this->list_index;
	std::cout << std::setfill('-') << std::setw(45) << "-" << std::endl;
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10) << "index";
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10) << "first_name";
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10) << "last_name";
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10) << "nick_name";
	std::cout << "|" << std::endl;
	std::cout << std::setfill('-') << std::setw(45) << "-" << std::endl;
	for (int i = 0; i < last; i++)
	{
		std::cout << "|";
		this->phone_list[i].display_index();
		this->phone_list[i].diplay_first_name();
		this->phone_list[i].diplay_last_name();
		this->phone_list[i].diplay_nick_name();
		std::cout << std::endl;
	}
	std::cout << std::setfill('-') << std::setw(45) << "-" << std::endl;
	temp = cmd_input("select index");
	if (check_digit(temp) == true && temp.length() == 1)
		input = temp[0] - '0';
	else
		input = -1;
	if (input > last || input <= 0)
		std::cout << "wrong index" << std::endl;
	else
		phone_list[input - 1].show_info();
}

void PhoneBook::book_exit(void)
{
	exit(1);
}

std::string cmd_input(std::string prompt)
{
	std::string temp;
	bool		flag = false;
	int			i = 0;
	int			j = 0;

	std::cout << prompt << " :";
	while (std::getline(std::cin, temp))
	{
		i = 0;
		j = 0;
		while (temp[i] != '\0')
		{
			if (isspace(temp[i]) == false)
				j++;
			i++;
		}
		if (j != 0)
		{
			flag = true;
			break;
		}
		std::cout << prompt << " :";
	}
	if (flag == false)
		exit(1);
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