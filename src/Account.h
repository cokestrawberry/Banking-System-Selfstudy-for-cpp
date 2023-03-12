#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

class Account
{
private:
	int accID;			//Account
	int balance;		//balance
	String cusName;		//customer's name
	
public:
	Account(int ID, int money, String name);
	//Account(const Account & ref);
	//Account& operator=(const Account& ref);
	
	int getAccID() const;
	virtual void deposit(int money);
	int withdraw(int money);
	void showAccInfo() const;
	//~Account();
};
#endif