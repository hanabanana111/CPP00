#include"./PhoneBook.hpp"
#include"./Contact.hpp"
#include <iostream>
#include <string>

int main()
{
    std::string command = "";
    PhoneBook phoneBook;

    while(1)
    {
        std::cout << "-----------------------------" << std::endl;
        std::cout << "Command(EXIT, SEARCH, ADD)" << std::endl;
        std::cin >> command;
        if (command.compare("EXIT") == SAME)
            phoneBook.exitPhoneBook();
        else if (command.compare("SEARCH") == SAME)
            phoneBook.searchContact();
        else if (command.compare("ADD") == SAME) 
            phoneBook.addContact();
        else if (std::cin.fail() || std::cin.bad() || std::cin.eof())
            break;
        else
            std::cout << "Invalid command" << std::endl;
    }
}
