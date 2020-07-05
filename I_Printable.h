#ifndef _I_PRINTABLE_H_
#define _I_PRINTABLE_H_
#include <iostream>

class I_Printable
{
	friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj)
	{
		obj.display(os);
		return os;
	}

public:
	virtual void display(std::ostream &os) const = 0;
	virtual ~I_Printable() = default;
};

#endif // !_I_PRINTABLE_H_


