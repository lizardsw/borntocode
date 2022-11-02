#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
    private :
        int index;
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    public :
        Contact();
        void set_info(int index, std::string buffer[]);
        void show_info(void);
        void diplay_first_name(void);
        void diplay_last_name(void);
        void diplay_nick_name(void);
        void diplay_phone_number(void);
        void diplay_darkest_secret(void);
        ~Contact();
};

void display_context(std::string context);

#endif