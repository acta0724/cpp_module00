/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiwasa <kiwasa@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:25:23 by kiwasa            #+#    #+#             */
/*   Updated: 2025/04/24 02:26:44 by kiwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <cstdlib>
#include "phoneBook.hpp"

std::string getNonEmptyLine(const std::string& prompt) {
    std::string line;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, line);
        if (!line.empty())
            return line;
        std::cout << "[Error] Input is empty. Please try again.\n";
    }
}

std::string getNumericLine(const std::string& prompt) {
    std::string line;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, line);
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
        std::cout << "Enter index to view details: ";
        std::getline(std::cin, line);
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
        index = ::atoi(line.c_str());
        if (index < 0 || index >= phoneBook.getContactCount()) {
            std::cout << "[Error] Index is out of range.\n";
            continue;
        }
        return index;
    }
}

int main()
{
	PhoneBook phoneBook;
	std::string command;

	while(true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (command == "ADD")
		{
			addContactToPhoneBook(phoneBook);
		}
		else if(command == "SEARCH")
		{
			phoneBook.searchContacts();
			int index = getValidIndex(phoneBook);
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