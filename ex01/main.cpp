/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiwasa <kiwasa@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:25:23 by kiwasa            #+#    #+#             */
/*   Updated: 2025/04/27 20:50:50 by kiwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <limits>
#include "phoneBook.hpp"

std::string getNonEmptyLine(const std::string& prompt) {
    std::string line;
    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, line))
        {
            std::cerr << "\nEOF detected. Exiting program." << std::endl;
            std::exit (1);
        }
        if (!line.empty())
            return line;
        std::cout << "[Error] Input is empty. Please try again.\n";
    }
}

std::string getNumericLine(const std::string& prompt) {
    std::string line;
    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, line))
        {
            std::cerr << "\nEOF detected. Exiting program." << std::endl;
            std::exit (1);
        }
        bool allDigit = !line.empty();
        for (std::string::size_type i = 0; i < line.size(); ++i) {
			char c = line[i];
            if (!std::isdigit(static_cast<unsigned char>(c))) {
                allDigit = false;
                break;
            }
        }
        if (allDigit)
            return line;
		if (line.empty())
			std::cout << "[Error] Input is empty. Please try again.\n";
		else
        	std::cout << "[Error] Contains non-numeric characters. Please enter only numbers.\n";
    }
}

void addContactToPhoneBook(PhoneBook& phoneBook)
{
	Contact newContact;

	std::string first   = getNonEmptyLine("Enter first name: ");
    std::string last    = getNonEmptyLine("Enter last name: ");
    std::string nickname= getNonEmptyLine("Enter nickname: ");
    std::string phone   = getNumericLine  ("Enter phone number: ");
    std::string secret  = getNonEmptyLine("Enter darkest secret: ");

	newContact.setDetails(first, last, nickname, phone, secret);
	phoneBook.addContact(newContact);
}

int PhoneBook::getContactCount() const
{
    return currentSize;
}

int getValidIndex(const PhoneBook& phoneBook)
{
    std::string line;
    int index;

    while (true) {
        if (phoneBook.getContactCount() == 0)
        {
            std::cout << "no phone book!!!\n";
            return -1;
        }
        std::cout << "Enter index to view details: ";
        if (!std::getline(std::cin, line))
        {
            std::cerr << "\nEOF detected. Exiting program." << std::endl;
            std::exit (1);
        }
        if (line.empty()) {
            std::cout << "[Error] Input is empty. Please try again.\n";
            continue;
        }
        bool allDigit = true;
        for (std::size_t i = 0; i < line.size(); ++i) {
            if (!std::isdigit(static_cast<unsigned char>(line[i]))) {
                allDigit = false;
                break;
            }
        }
        if (!allDigit) {
            std::cout << "[Error] Contains non-numeric characters. Please enter only numbers.\n";
            continue;
        }
        char* endptr;
        long long tempIndex = std::strtoll(line.c_str(), &endptr, 10);
        if (tempIndex > std::numeric_limits<int>::max()) {
            std::cout << "[Error] Number is too large or too small. Please enter a valid index.\n";
            continue;
        }
        index = static_cast<int>(tempIndex);
        if (index < 0 || index >= phoneBook.getContactCount()) {
            std::cout << "[Error] Index is out of range.\n";
            continue;
        }
        return index;
    }
}

int main(int argc, char **argv)
{
	PhoneBook phoneBook;
	std::string command;

    if (argc != 1)
    {
        std::cerr << argv[0] << " is without argument!\n";
        return (1);
    }
	while(true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
        {
            std::cerr << "\nEOF detected. Exiting program." << std::endl;
            break ;
        }
		if (command == "ADD")
		{
			addContactToPhoneBook(phoneBook);
		}
		else if(command == "SEARCH")
		{
			phoneBook.searchContacts();
			int index = getValidIndex(phoneBook);
            if (index != -1)
			    phoneBook.displayContacts(index);
		}
		else if (command == "EXIT")
		{
			break;
		}
		else
		{
			std::cout << "Invalid command!" << std::endl;
		}
	}
}