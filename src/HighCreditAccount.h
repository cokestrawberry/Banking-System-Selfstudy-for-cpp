#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "NormalAccount.h"
#include "String.h"

class highCreditAccount : public normalAccount
{
private:
	int specialRate;
public:
	highCreditAccount(int ID, int money, String name, int rate, int special) : normalAccount(ID, money, name, rate), specialRate(special)
	{
	//empty
	}
	
	virtual void deposit(int money)
	{
		normalAccount::deposit(money);
		Account::deposit(money*(specialRate/100.0));
	}
};
#endif