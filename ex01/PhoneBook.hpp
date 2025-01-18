#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include"./Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cassert>
#include <cctype>
#include <algorithm>

# define TRUE 1
# define FALSE 0
# define SAME 0

class PhoneBook
{
    public:
        PhoneBook();
        void addContact();
        void searchContact();
        void exitPhoneBook();
    private:
        Contact contacts[8];
        int index_count_;
        bool cinAddInfo(const std::string& msg, std::string& str);
        bool cinAddPhoneNumber(const std::string& msg, std::string& phone_number);
        bool checkPhoneNumber(std::string& phone_number);
        void print10Chars(std::string str);
        void printAllContacts();
        bool checkIndex(const std::string& str_index, int& index);
        void printOneContact(const int& in_index);
};

#endif