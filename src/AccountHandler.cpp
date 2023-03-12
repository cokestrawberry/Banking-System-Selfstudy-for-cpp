#include "BankingSystemDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "String.h"

void AccountHandler::showMenu(void) const	//can cause error
{
	cout<<"----- MENU -----"<<endl;
	cout<<"1. Create Account"<<endl;
	cout<<"2. Deposit"<<endl;
	cout<<"3. Withdrawal"<<endl;
	cout<<"4. Inquire All Account Information"<<endl;
	cout<<"5. Exit Program"<<endl;
}

void AccountHandler::createAccount(void)
{
	int sel;
	
	cout<<"[Choose account type]"<<endl;
	cout<<"1. Normal account ";
	cout<<"2. Credit account "<<endl;
	cout<<endl<<"Choose : ";
	cin>>sel;
	
	if(sel==NORMAL)
	{
		createNormalAccount();
	}
	else
	{
		createCreditAccount();
	}
}

void AccountHandler::createNormalAccount(void)
{
	int id;
	//char name[NAME_LEN];
	String name;
	int balance;
	int interRate;
	
	cout<<"[Create Account]"<<endl;
	cout<<"Account ID : ";
	cin>>id;
	cout<<"Name : ";
	cin>>name;
	cout<<"Deposit Amount : ";
	cin>>balance;
	cout<<"Interest Rates : ";
	cin>>interRate;
	cout<<endl;
	
	accArr[accNum++]=new normalAccount(id,balance,name,interRate);
}

void AccountHandler::createCreditAccount(void)
{
	int id;
	//char name[NAME_LEN];
	String name;
	int balance;
	int interRate;
	int creditLevel;
	
	cout<<"[Create Account]"<<endl;
	cout<<"Account ID : ";
	cin>>id;
	cout<<"Name : ";
	cin>>name;
	cout<<"Deposit Amount : ";
	cin>>balance;
	cout<<"Interest Rates : ";
	cin>>interRate;
	cout<<"Credit Level(1 to A, 2 to B, 3 to C) : ";
	cin>>creditLevel;
	cout<<endl;
	
	switch(creditLevel)
	{
	case 1:
		accArr[accNum++]=new highCreditAccount(id,balance,name,interRate,LEVEL_A);
		break;
	case 2:
		accArr[accNum++]=new highCreditAccount(id,balance,name,interRate,LEVEL_B);
		break;
	case 3:
		accArr[accNum++]=new highCreditAccount(id,balance,name,interRate,LEVEL_C);
	}
}

void AccountHandler::depositMoney(void)
{
	int money;
	int id;
	cout<<"[Deposit]"<<endl;
	cout<<"Account ID : ";
	cin>>id;
	cout<<"Deposit Amount : ";
	cin>>money;
	
	for(int i=0;i<accNum;i++)
	{
		if(accArr[i]->getAccID()==id)
		{
			accArr[i]->deposit(money);
			cout<<"*** Deposit Complete! ***"<<endl<<endl;
			return;
		}
	}
	cout<<"***** Invalid Account ID! ******"<<endl<<endl;
}

void AccountHandler::withdrawMoney(void)
{
	int money;
	int id;
	cout<<"[Withdrawal]"<<endl;
	cout<<"Account ID : ";
	cin>>id;
	cout<<"Withdrawal Amount : ";
	cin>>money;
	
	for(int i=0;i<accNum; i++)
	{
		if(accArr[i]->getAccID()==id)
		{
			if(accArr[i]->withdraw(money)==0)
			{
				cout<<"***** Not Enough Balance! *****"<<endl<<endl;
				return;
			}
			
			cout<<"*** Withdrawal Complete! ***"<<endl<<endl;
			return;
		}
	}
	cout<<"***** Invalid Account ID! ******"<<endl<<endl;
}

AccountHandler::AccountHandler() : accNum(0)
{
	//empty
}

void AccountHandler::showAllAccInfo(void) const
{
	for(int i=0;i<accNum;i++)
	{
		accArr[i]->showAccInfo();
		cout<<endl;
	}
}

AccountHandler::~AccountHandler()
{
	for(int i=0;i<accNum;i++)
	{
		delete accArr[i];
	}
}