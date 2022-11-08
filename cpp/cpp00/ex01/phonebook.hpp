/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwch <seongwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:15:58 by seongwch          #+#    #+#             */
/*   Updated: 2022/11/08 14:16:11 by seongwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <stdlib.h>

class PhoneBook
{
    private :
        Contact phone_list[8];
        std::string buffer[5];
        int list_index;
        bool is_full;
    public :
        PhoneBook();
        void    add(void);
        void    search(void);
        void    book_exit(void);
        ~PhoneBook();
};

std::string cmd_input(std::string prompt);
bool    check_digit(std::string phone_number);

#endif