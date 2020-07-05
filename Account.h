#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <cstring>
#include <string>
#include "I_Printable.h"

enum class deposit_status // using "class" to avoid global scope
{
	OK,
	too_high,
	too_small
};

class Account : public I_Printable
{
	//friend std::ostream &operator<<(std::ostream &os, const Account &rhs);
	friend std::istream &operator>>(std::istream &in, Account &rhs);
private:
	static constexpr const char *def_name = "Unknown Acc Name";
	static constexpr const char *def_user = "Unknown Acc Username";
	static constexpr double def_bl = 0.0;
protected:
	char *name;
	std::string username;
	double balance;
public:
	//Account();																		// No-args constructor
	Account(const char *n = def_name, std::string nn = def_user, double bl = def_bl);	// Overloaded constructor
	Account(const Account &src);						// Copy constructor
	Account(Account &&src);								// Move constructor
	virtual ~Account();									// Destructor;

	Account &operator=(const Account &rhs);				// Copy assignment
	Account &operator=(Account &&rhs);					// Move assignment

	Account operator-() const;							// Make lowercase
	Account operator+(const Account &rhs) const;		// Concatenate
	bool operator<(const Account &rhs) const;
	bool operator==(const Account &rhs) const;				// Equality

	virtual void display(std::ostream &os) const override;
	virtual bool deposit(double amount);
	bool withdraw(double amount);
	char *get_name() const;
	std::string get_user() const;
	double get_balance() const;
	deposit_status check_deposit_validity(double balance);
};

#endif // !_ACCOUNT_H_
