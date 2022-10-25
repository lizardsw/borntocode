#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
    private :
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    public :
        Contact();
        void setFirstName(std::string first_name);
        void setLastName(std::string last_name);
        void setNickName(std::string nickname);
        void setPhoneNumber(std::string phonenumber);
        void setDerkestSecret(std::string darkest_secret);
        ~Contact();
};



#endif