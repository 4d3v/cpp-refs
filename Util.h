#ifndef _UTIL_H_
#define _UTIL_H_
#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"

void display(const std::vector<Account *> &accs);
void deposit(std::vector<Account *> &accs, double amount);
void withdraw(std::vector<Account *> &accs, double amount);

#endif // !_UTIL_H_

