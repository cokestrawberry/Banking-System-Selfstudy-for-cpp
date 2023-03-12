#include "BankingSystemDecl.h"
#include "Account.h"

Account::Account(int ID, int money, String name) : accID(ID), balance(money)
{
	//cusName=new char[strlen(name)+1];
	//strcpy(cusName,name);
	cusName=name;
}

/*
Account::Account(const Account & ref) : accID(ref.accID), balance(ref.balance)
{
	cusName=new char[strlen(ref.cusName)+1];
	strcpy(cusName, ref.cusName);
}

Account& Account::operator=(const Account& ref)
{
	accID=ref.accID;
	balance=ref.balance;
	
	delete []cusName;
	cusName=new char[strlen(ref.cusName)+1];
	strcpy(cusName, ref.cusName);
	return *this;
}
*/

int Account::getAccID() const
{
	return accID;
}

void Account::deposit(int money)
{
	balance+=money;
}

int Account::withdraw(int money)
{
	if(balance<money)
	{
		return 0;
	}
	balance-=money;
	return money;
}

void Account::showAccInfo() const
{
	cout<<"Account ID : "<<accID<<endl;
	cout<<"Name : "<<cusName<<endl;
	cout<<"Balance : "<<balance<<endl;
}

/*
Account::~Account()
{
	delete []cusName;
}
*/