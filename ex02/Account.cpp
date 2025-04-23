/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiwasa <kiwasa@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:58:08 by kiwasa            #+#    #+#             */
/*   Updated: 2025/04/24 01:47:47 by kiwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp()
{
	std::time_t t;
	std::time(&t);
	std::tm* tm_ptr = std::localtime(&t);
	char buf[20];
	std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S]", tm_ptr);
	std::cout << buf;
}

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts),
	  _amount(initial_deposit),
	  _nbDeposits(0),
	  _nbWithdrawals(0)
{
	++_nbAccounts;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";closed" << std::endl;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout	<< " accounts:" << _nbAccounts
				<< ";total:" << _totalAmount
				<< ";deposits:" << _totalNbDeposits
				<< ";withdrawals:" << _totalNbWithdrawals
				<< std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";deposit:" << deposit;
	_amount += deposit;
	++_nbDeposits;
	_totalAmount += deposit;
	++_totalNbDeposits;
	std::cout << ";amount:" << _amount
				<< ";nb_deposits:" << _nbDeposits
				<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";withdrawal:";
	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	++_nbWithdrawals;
	_totalAmount -= withdrawal;
	++_totalNbWithdrawals;
	std::cout << withdrawal
				<< ";amount:" << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals
				<< std::endl;
	return true;
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals
				<< std::endl;
}