#include "BankingSystemDecl.h"
#include "AccountHandler.h"

int main(void)
{
	AccountHandler manager;
	int choice;
	
	while(1)
	{
		manager.showMenu();
		cout<<"Choose : ";
		cin>>choice;
		cout<<endl;
		
		switch(choice)
		{
			case CREATE:
				manager.createAccount();
				break;
			case DEPOSIT:
				manager.depositMoney();
				break;
			case WITHDRAW:
				manager.withdrawMoney();
				break;
			case INQUIRE:
				manager.showAllAccInfo();
				break;
			case EXIT:
				return 0;
			default:
				cout<<"***** Invalid selection! *****"<<endl<<endl;
		}
	}
}