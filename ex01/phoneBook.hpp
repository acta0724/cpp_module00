/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiwasa <kiwasa@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:21:58 by kiwasa            #+#    #+#             */
/*   Updated: 2025/04/24 02:21:41 by kiwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int currentSize;
	public:
		PhoneBook();
		void addContact(const Contact& contact);
		void searchContacts() const;
		void displayContacts(int index) const;
		int getContactCount() const;
};

#endif