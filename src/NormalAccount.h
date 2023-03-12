#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"
#include "String.h"

class normalAccount : public Account
{
private:
	int interRate;	//interest rate repressented as % ratio
public:
	normalAccount(int ID, int money, String name, int rate) : Account(ID, money, name), interRate(rate)
	{
		//empty
	}
	
	virtual void deposit(int money)
	{
		Account::deposit(money);
		Account::deposit(money*(interRate/100.0));
	}
};
#endif