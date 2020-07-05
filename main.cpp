#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "Util.h"
#include "I_Printable.h"
#include "Account.h"
#include "Savings_Account.h"

int main()
{
	std::cout.precision(2);
	std::cout << std::fixed;
	//std::cin.clear();
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

	Account *p1 = new Account("Nick", "Nico");
	Account *p2 = new Account("Craig", "Johnson", 1000);
	Account *p3 = new Savings_Account("Amariksu", "Kinaga", 1000);
	Account *p4 = new Savings_Account("Joshua", "Miriapodes", 1500, 6.5);
	std::vector<Account *> accs{ p1, p2, p3, p4 };
	display(accs);
	deposit(accs, 1000);
	withdraw(accs, 1500);

	Account *acc_to_find = new Savings_Account("Amariksu", "Kinaga");
	bool f = false;
	for (auto &acc : accs)
	{
		if (*acc == *acc_to_find)
			f = true;
	}
	std::cout << std::boolalpha << std::endl;
	std::cout << "Found " << acc_to_find->get_name()
		<< acc_to_find->get_user() << "? " << f;

	Savings_Account p("Nick", "Nico");
	Savings_Account pp{ "Camo", "Mans", 2500 };
	Savings_Account ppp("Craig", "Johnson", 1000);
	Savings_Account pppp{ "Mitigarito", "Armstrong", 820 };
	std::vector<Savings_Account> vec{ p, pp, ppp, pppp };
	double i = 0;
	std::for_each(vec.begin(), vec.end(),
		[&i](Savings_Account x) { i += x.get_balance(); });

	std::cout << "\nTotal bank's funds: " << i << '\n';

	return 0;
}