#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
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