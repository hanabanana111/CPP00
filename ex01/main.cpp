#include"PhoneBook.hpp"
#include"Contact.hpp"
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
        std::getline(std::cin, command);
        if (std::cin.fail() || std::cin.bad() || std::cin.eof())
        {
            std::cerr << "Error" << std::endl;
            break;
        }
        if(command.empty())
        {
            std::cout << "Empty Command" << std::endl;
            continue;
        }
        if (command.compare("EXIT") == SAME)
            phoneBook.exitPhoneBook();
        else if (command.compare("SEARCH") == SAME)
            phoneBook.searchContact();
        else if (command.compare("ADD") == SAME) 
            phoneBook.addContact();
        else
            std::cout << "Invalid command" << std::endl;
    }
}
