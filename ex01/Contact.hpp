#ifndef Contact_HPP
#define Contact_HPP

#include <iostream>
#include <string>

class Contact
{
    public:
        Contact();
        void setIndex(const int& new_index);
        int getIndex() const;
        void setFirstName(const std::string& new_first_name);
        std::string getFirstName() const;
        void setLastName(const std::string& new_last_name);
        std::string getLastName() const;
        void setNickname(const std::string& new_nickname);
        std::string getNickname() const;
        void setPhoneNumber(const std::string& new_phone_number);
        std::string getPhoneNumber() const;
        void setDarkestSecret(const std::string& new_darkest_secret);
        std::string getDarkestSecret() const;
    private:
        int index_;
        std::string first_name_;
        std::string last_name_;
        std::string nickname_;
        std::string phone_number_;
        std::string darkest_secret_;
};

#endif