#include"./Contact.hpp"

Contact::Contact() : 
index_(-1),
first_name_(""),
last_name_(""),
nickname_(""),
phone_number_(""),
darkest_secret_("")
{
}

void Contact::setIndex(const int& new_index)
{
    index_ = new_index;
}

int Contact::getIndex()
{
    return index_;
}

void Contact::setFirstName(const std::string& new_first_name)
{
    first_name_ = new_first_name;
}

std::string Contact::getFirstName()
{
    return first_name_;
}

void Contact::setLastName(const std::string& new_last_name)
{
    last_name_ = new_last_name;
}

std::string Contact::getLastName()
{
    return last_name_;
}

void Contact::setNickname(const std::string& new_nickname)
{
    nickname_ = new_nickname;
}

std::string Contact::getNickname()
{
    return nickname_;
}

void Contact::setPhoneNumber(const std::string& new_phone_number)
{
    phone_number_ = new_phone_number;
}

std::string Contact::getPhoneNumber()
{
    return phone_number_;
}

void Contact::setDarkestSecret(const std::string& new_darkest_secret)
{
    darkest_secret_ = new_darkest_secret;
}

std::string Contact::getDarkestSecret()
{
    return darkest_secret_;
}