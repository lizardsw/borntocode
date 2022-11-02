#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

class PhoneBook
{
    private :
        Contact phone_list[8];
        std::string buffer[5];
        int list_index;
        bool is_full;
    public :
        PhoneBook();
        void    show_all(void);
        void    add(void);
        void    search(void);
        ~PhoneBook();
};

std::string cmd_input(std::string prompt);
bool    check_digit(std::string phone_number);



#endif