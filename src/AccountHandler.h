#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "BoundCheckArray.h"

class AccountHandler
{
private:
	BoundCheckArray<Account*> accArr;		//array to save account
	int accNum;					//number of account
public:
	AccountHandler();
	void showMenu(void) const;			//show menu page
	void createAccount(void);			//function for creating account
	void depositMoney(void);			//deposit
	void withdrawMoney(void);			//withdraw
	void showAllAccInfo(void) const;	//findout balance
	~AccountHandler();
protected:
	void createNormalAccount(void);
	void createCreditAccount(void);
};
#endif