#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_
#include <iostream>
#include "Account.h"

// To differenciate... deposit here increments amount * int_rate percentage
class Savings_Account: public Account
{
	//friend std::ostream &operator<<(std::ostream &os, const Savings_Account &rhs);
private:
	static constexpr const char *def_name = "Unknown Savings Acc name";
	static constexpr const char *def_user = "Unknown Savings Acc username";
	static constexpr double def_bl = 0.0;
	static constexpr double def_int_rate = 5.0;
protected:
	double int_rate;
public:
	Savings_Account(
		const char *n = def_name, 
		std::string nn = def_user, 
		double bl = def_bl, 
		double int_rate = def_int_rate 
	);
	virtual ~Savings_Account() = default;
	virtual void display(std::ostream &os) const override;
	virtual bool deposit(double amount) override;
	// Inherits Account::withdraw()
	bool operator==(const Savings_Account &rhs) const;
	bool operator<(const Savings_Account &rhs) const;
};

#endif // !_SAVINGS_ACCOUNT_H_
