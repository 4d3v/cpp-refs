#include "Account.h"

//Account::Account()
//	: name{ nullptr }
//{
//	name = new char[1];
//	*name = '\0';
//}

Account::Account(const char *n, const std::string nn, double bl)
	: name{ nullptr }, username{ nn }, balance{ bl }
{
	if (n == nullptr)
	{
		name = new char[1];
		*name = '\0';
	}
	else
	{
		name = new char[std::strlen(n) + 1];
		std::strcpy(name, n);
	}
}

// Copy constructor
Account::Account(const Account &src)
	:name{ nullptr }, username{ src.username }, balance{ src.balance }
{
	name = new char[std::strlen(src.name) + 1];
	std::strcpy(name, src.name);
}

// Move constructor
Account::Account(Account &&src)
	: name{ src.name }, username{ src.username }, balance{ src.balance }
{
	src.name = nullptr;
}

// Destructor
Account::~Account() { delete[] name; }

// Copy assignment
Account &Account::operator=(const Account &rhs)
{
	std::cout << "Copy assignment being called\n";

	// Has to dereference pointer cos the method expects a reference back
	if (this == &rhs) return *this; 

	delete[] this->name; // Or delete[] name;
	this->name = new char[std::strlen(rhs.name) + 1];
	std::strcpy(this->name, rhs.name);
	username = rhs.username;
	balance = rhs.balance;
	return *this;
}

Account &Account::operator=(Account &&rhs)
{
	std::cout << "Move assignment being called\n";

	// Has to dereference pointer cos the method expects a reference back
	if (this == &rhs) return *this;

	delete[] name;
	name = rhs.name;
	username = rhs.username;
	balance = rhs.balance;
	rhs.name = nullptr;
	return *this;
}

// Make lowercase
Account Account::operator-() const
{
	char *buff = new char[std::strlen(name) + 1];
	std::strcpy(buff, name);
	std::string buff2 = username;
	for (unsigned int i = 0;
		i < (std::strlen(buff) > buff2.length() ? std::strlen(buff) : buff2.length());
		++i)
	{
		buff[i] = tolower(buff[i]);
		buff2[i] = tolower(buff2[i]);
	}

	Account temp{ buff, buff2 };
	delete[] buff;
	return *this;
}

// Concatenate
Account Account::operator+(const Account &rhs) const
{
	char *buff = new char[std::strlen(name) + std::strlen(rhs.name) + 1];
	std::string buff2 = username + rhs.username;
	std::strcpy(buff, name);
	std::strcat(buff, rhs.name);
	Account temp{ buff, buff2 };
	delete[] buff;
	return temp;
}

// Equality
bool Account::operator==(const Account &rhs) const
{
	return (std::strcmp(name, rhs.name) == 0
		&& username == rhs.username);
		//&& balance == rhs.balance);
}

bool Account::operator<(const Account &rhs) const
{
	return balance > rhs.balance;
}

void Account::display(std::ostream &os) const 
{
	os << "| Name: " << name 
	   << ", Username: " << username 
	   << ", balance: " << balance 
	   << " |";
}

bool Account::deposit(double amount)
{
	if (amount > 0.0)
	{
		balance += amount;
		return true;
	}
	else
		return false;
}

bool Account::withdraw(double amount)
{
	if (balance - amount >= 0.0)
	{
		balance -= amount;
		return true;
	}
	else
		return false;
}

char *Account::get_name() const
{
	return name;
}
std::string Account::get_user() const
{
	return username;
}
double Account::get_balance() const
{
	return balance;
}

deposit_status Account::check_deposit_validity(double amount)
{
	if (amount > 5000.0)
		return deposit_status::too_high;
	else if (amount < 2)
		return deposit_status::too_small;
	else
		return deposit_status::OK;
}

//std::ostream &operator<<(std::ostream &os, const Account &rhs)
//{
//	os << "| Name: " << rhs.name 
//	   << ", Username: " << rhs.username 
//	   << ", balance: " << rhs.balance 
//	   << " |";
//	return os;
//}

std::istream &operator>>(std::istream &in, Account &rhs)
{
	char *buff = new char[1000];
	in >> buff;
	std::string buff2;
	in >> buff2;
	double buff3;
	in >> buff3;
	rhs = Account{ buff, buff2, buff3 };
	delete[] buff;
	return in;
}
