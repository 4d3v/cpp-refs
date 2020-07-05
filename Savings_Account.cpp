#include "Savings_Account.h"

Savings_Account::Savings_Account(const char *n, std::string nn, double bl, double int_rate)
	: Account(n, nn, bl), int_rate{ int_rate } {}

bool Savings_Account::deposit(double amount)
{
	amount += amount * int_rate / 100;
	return Account::deposit(amount);
}

void Savings_Account::display(std::ostream &os) const
{
	os << "| Name: " << name 
	   << ", Username: " << username 
	   << ", Balance: " << balance 
	   << ", Interest rate: " << int_rate
	   << "% |";
}

bool Savings_Account::operator==(const Savings_Account &rhs) const
{
	return (std::strcmp(Account::name, rhs.name) == 0
		&& Account::username == rhs.username);
		//&& Account::get_balance() == rhs.balance);
}

bool Savings_Account::operator<(const Savings_Account &rhs) const
{
	return Account::get_balance() > rhs.balance;
}

//std::ostream &operator<<(std::ostream &os, const Savings_Account &rhs)
//{
//	os << "Savings_Account => "
//	   << "| Name: " << rhs.name 
//	   << ", Username: " << rhs.username 
//	   << ", Balance: " << rhs.balance 
//	   << ", Interest rate: " << rhs.int_rate
//	   << "% |";
//	return os;
//}
