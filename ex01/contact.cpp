/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiwasa <kiwasa@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:44:56 by kiwasa            #+#    #+#             */
/*   Updated: 2025/04/22 20:41:55 by kiwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include <iostream>
#include <iomanip>

void Contact::setDetails(const std::string& first, \
	const std::string& last, const std::string& nickname, \
	const std::string& phone, const std::string& secret)
{
	firstName = first;
	lastName = last;
	this->nickname = nickname;
	phoneNumber = phone;
	darkestSecret = secret;
}

void Contact::display() const
{
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Darkest secret: " << darkestSecret << std::endl;
}