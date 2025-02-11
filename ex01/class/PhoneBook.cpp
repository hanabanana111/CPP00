#include"./PhoneBook.hpp"

PhoneBook::PhoneBook():
    index_count_(0)
{}

void PhoneBook::addContact()
{
    std::string new_first_name;
    std::string new_last_name;
    std::string new_nickname;
    std::string new_phone_number;
    std::string new_darkest_secret;

    index_count_ %= 8;
    if (cinAddInfo("Please enter first name", new_first_name) == FALSE)
        return;
    if (cinAddInfo("Please enter last name", new_last_name) == FALSE)
        return;
    if (cinAddInfo("Please enter nickname", new_nickname) == FALSE)
        return;
    if (cinAddPhoneNumber("Please enter phone number", new_phone_number) == FALSE)
        return;
    if (cinAddInfo("Please enter darkest secret", new_darkest_secret) == FALSE)
        return;
    contacts[index_count_].setIndex(index_count_);
    contacts[index_count_].setFirstName(new_first_name);
    contacts[index_count_].setLastName(new_last_name);
    contacts[index_count_].setNickname(new_nickname);
    contacts[index_count_].setPhoneNumber(new_phone_number);
    contacts[index_count_].setDarkestSecret(new_darkest_secret);
    index_count_++;
    std::cout << "Added new contact" << std::endl;
}

bool PhoneBook::cinAddInfo(const std::string& msg, std::string& str)
{
    std::cout << msg << std::endl;
    std::getline(std::cin, str);
    if (std::cin.fail() || std::cin.bad() || std::cin.eof())
    {
        std::cerr << "Error" << std::endl;
        return FALSE;
    }
    else if(str.empty())
    {
        std::cerr << "Empty input" << std::endl;
        return FALSE;
    }
    else
        return TRUE;
}

bool PhoneBook::cinAddPhoneNumber(const std::string& msg, std::string& phone_number)
{
    std::cout << msg << std::endl;
    std::getline(std::cin, phone_number);
    if (std::cin.fail() || std::cin.bad() || 
        std::cin.eof() || checkPhoneNumber(phone_number) == FALSE || phone_number.empty())
    {
        std::cerr << "Invalid phone number" << std::endl;
        return FALSE;
    }
    else if(phone_number.empty())
    {
        std::cerr << "Empty input" << std::endl;
        return FALSE;
    }
    else
        return TRUE;
}

bool PhoneBook::checkPhoneNumber(std::string& phone_number)
{
    int len;

    len = phone_number.length();
    if (!(len > 2 && len < 16))
            return FALSE;
    for(int i = 0;phone_number[i]; i++)
    {
        if(!std::isdigit(phone_number[i]))
        return FALSE;
    }
    return TRUE;
}

void PhoneBook::searchContact()
{
    std::string str_index;
    int index;
    
    if (contacts[0].getIndex() == -1)
    {
        std::cout << "Empty PhoneBook" << std::endl;
        return;
    }
    printAllContacts();
    std::cout << "Enter index" << std::endl;
    std::getline(std::cin, str_index);
    if (std::cin.fail() || std::cin.bad() || std::cin.eof())
    {
        std::cerr << "Invalid index" << std::endl;
        return ;
    }
    else if(str_index.empty())
    {
        std::cerr << "Empty input" << std::endl;
        return ;
    }
    if(str_index.length() == 1 && checkIndex(str_index, index))
        printOneContact(index);
    else
        std::cout << "Invalid index" << std::endl;
}

bool PhoneBook::checkIndex(const std::string& str_index, int& index)
{
    char c;
    std::string num = "01234567";

    c = str_index[0];
    if (num.find(c) != std::string::npos)
    {
        index = c - '0';
        return (TRUE);
    }
    return (FALSE);
}
void PhoneBook::print10Chars(std::string str)
{
    int len;
    std::string print_str;

    len = str.length();
    if (len > 10)
    {
        print_str = str.substr(0,9);
        print_str.push_back('.');
    }
    else
        print_str = str;
    std::cout << std::setw(10) << print_str << std::flush;
}

void PhoneBook::printAllContacts()
{
    Contact *p;

    std::cout << "Index|First Name| Last Name|  Nickname" << std::endl;
    for(int i = 0; i < 8; i++)
    {
        p = &contacts[i];
        if (p->getIndex() == -1)
            break;
        std::cout << std::setw(5) << i << '|' << std::flush;
        print10Chars(p->getFirstName());
        std::cout << '|' << std::flush;
        print10Chars(p->getLastName());
        std::cout << '|' << std::flush;
        print10Chars(p->getNickname());
        std::cout << std::endl;
    }
}

void PhoneBook::printOneContact(const int& in_index)
{
    Contact *p;

    p = &contacts[in_index];
    if (p->getIndex() == -1)
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    std::cout << "****************************" << std::endl;
    std::cout << "Index          : " << p->getIndex() << std::endl;
    std::cout << "First Name     : " << p->getFirstName() << std::endl;
    std::cout << "Last Name      : " << p->getLastName() << std::endl;
    std::cout << "Nickname       : " << p->getNickname() << std::endl;
    std::cout << "Phone Number   : " << p->getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret : " << p->getDarkestSecret() << std::endl;
    std::cout << "****************************" << std::endl;
}

void PhoneBook::exitPhoneBook()
{
    std::exit(0);
}
