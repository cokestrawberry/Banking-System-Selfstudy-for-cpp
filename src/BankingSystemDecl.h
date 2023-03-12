#ifndef __BANKING_SYSTEM_DECL_H__
#define __BANKING_SYSTEM_DECL_H__

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;
const int NAME_LEN=20;

//MENU INDEX
enum {CREATE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

//CREDIT LEVEL
enum {LEVEL_A=7, LEVEL_B=4, LEVEL_C=2};

//TYPE OF ACCOUNT
enum {NORMAL=1, CREDIT=2};
#endif