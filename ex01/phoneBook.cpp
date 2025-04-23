/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiwasa <kiwasa@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:42:37 by kiwasa            #+#    #+#             */
/*   Updated: 2025/04/22 20:41:17 by kiwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : currentSize(0) {}

void PhoneBook::addContact(const Contact& contact)
{
	if (currentSize < 8)
	{
		contacts[currentSize] = contact;
		++currentSize;
	}
	else
	{
		for(int i = 1; i < 8; ++i)
		{
			contacts[i - 1] = contacts[i];
		}
		contacts[7] = contact;
	}
}

void PhoneBook::searchContacts() const
{
	std::cout	<< std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << std::endl;
	std::cout	<< "---------------------------------------" << std::endl;
	
	for(int i = 0; i < currentSize; ++i)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << contacts[i].firstName.substr(0, 9) << ".|";
		std::cout << std::setw(10) << contacts[i].lastName.substr(0, 9) << ".|";
		std::cout << std::setw(10) << contacts[i].nickname.substr(0, 9) << "." << std::endl;
	}
}

void PhoneBook::displayContacts(int index) const
{
	if (index >= 0 && index < currentSize)
	{
		contacts[index].display();
	}
	else
	{
		std::cout << "Invalid index!" << std::endl;
	}
}