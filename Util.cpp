#include "Util.h"

void display(const std::vector<Account *> &accs)
{
	std::cout << "\n=== Accounts ===\n";
	for (const auto acc : accs)
		std::cout << *acc << std::endl;
}

void deposit(std::vector<Account *> &accs, double amount)
{
	std::cout << "\n=== Depositing to Accounts ===\n";
	for (auto acc : accs)
	{
		if (acc->deposit(amount))
		{
			std::cout << "Deposited " << amount << " to " << *acc << std::endl;
		}
		else
			std::cout << "Failed to deposit " << amount << " to " << *acc << std::endl;
	}
}

void withdraw(std::vector<Account *> &accs, double amount)
{
	std::cout << "\n=== Withdrawing from Accounts ===\n";
	for (auto &acc : accs)
	{
		if (acc->withdraw(amount))
		{
			std::cout << "Withdrew " << amount << " from " << *acc << std::endl;
		}
		else
			std::cout << "Failed to withdraw " << amount << " from " << *acc << std::endl;
	}
}
