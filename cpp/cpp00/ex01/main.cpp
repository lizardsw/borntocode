/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:15:52 by seongwch          #+#    #+#             */
/*   Updated: 2022/11/08 14:16:18 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook mybook;
	std::string book_ft;

	std::cout << "[[[ADD, SEARCH, EXIT]]]" << std::endl;
	while(std::getline(std::cin, book_ft))
	{
		if(book_ft.compare("EXIT") == 0)
			mybook.book_exit();
		else if (book_ft.compare("ADD") == 0)
			mybook.add();
		else if (book_ft.compare("SEARCH") == 0)
			mybook.search();
		std::cout << "[[[ADD, SEARCH, EXIT]]]" << std::endl;
	}
	return (0);
}