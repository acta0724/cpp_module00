/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiwasa <kiwasa@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:51:12 by kiwasa            #+#    #+#             */
/*   Updated: 2025/04/24 01:47:56 by kiwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>
#include <ctime>

class Account
{
	public:
		typedef Account t;
		Account(int initial_deposit);
		~Account();
		static void displayAccountsInfos();
		void makeDeposit(int deposit);
		bool makeWithdrawal(int withdrawal);
		void displayStatus() const;
	private:
		static void _displayTimestamp();
		static int _nbAccounts;
		static int _totalAmount;
		static int _totalNbDeposits;
		static int _totalNbWithdrawals;
		int _accountIndex;
		int _amount;
		int _nbDeposits;
		int _nbWithdrawals;
};

#endif