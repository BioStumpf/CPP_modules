// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"
#include <iostream>
#include <ctime>

//init the private class member variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
	: _accountIndex(_nbAccounts),
	  _amount(initial_deposit),
	  _nbDeposits(0),
	  _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += checkAmount();
	_displayTimestamp();
	std::cout 
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "created" <<std::endl;
}

Account::~Account( void )
{
	_nbAccounts--;
	_totalAmount -= checkAmount();
	_displayTimestamp();
	std::cout 
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "closed" <<std::endl;
};


//class member functions
int	Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return _totalAmount;
}

int	Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout
		<< "accounts:" << getNbAccounts() << ";"
		<< "total:" << getTotalAmount() << ";"
		<< "deposits:" << getNbDeposits() << ";"
		<< "withdrawals:" << getNbWithdrawals()
		<< std::endl;
}

//class instance functions
void	Account::makeDeposit( int deposit ) {
	int	old_amount = checkAmount();
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;

	_displayTimestamp();
	std::cout 
		<< "index:" << _accountIndex << ";"
		<< "p_amount:" << old_amount << ";"
		<< "deposit:" << deposit << ";"
		<< "amount:" << checkAmount() << ";"
		<< "nb_deposits:" << _nbDeposits
		<<std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	int	new_amount = checkAmount() - withdrawal;

	_displayTimestamp();
	if (new_amount < 0) {
		std::cout 
			<< "index:" << _accountIndex << ";"
			<< "p_amount:" << checkAmount() << ";"
			<< "withdrawal:refused"
			<< std::endl;
		return false;
	}
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	std::cout 
		<< "index:" << _accountIndex << ";"
		<< "p_amount:" << checkAmount() << ";"
		<< "withdrawal:" << withdrawal << ";"
		<< "amount:" << new_amount << ";"
		<< "nb_withdrawals:" << _nbWithdrawals
		<< std::endl;
	_amount = new_amount;
	return true;
}

int	Account::checkAmount( void ) const {
	return _amount;
}

void Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout 
		<< "index:" << _accountIndex << ";"
		<< "amount:" << checkAmount() << ";"
		<< "deposits:" << _nbDeposits << ";"
		<< "withdrawals:" << _nbWithdrawals
		<< std::endl;
}

//helper functions inside the scope of the class
void	Account::_displayTimestamp( void ) {
	std::time_t now = std::time(NULL);
	char buf[20];
	std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S]", std::localtime(&now));
	std::cout << buf << " ";
}

//private default constructor
Account::Account( void ) {};
