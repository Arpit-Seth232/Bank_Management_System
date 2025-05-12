#ifndef BANK_H
#define BANK_H

#include <bits/stdc++.h>
#include "../json.hpp"
#include "Account.h"

using json = nlohmann::json;
using namespace std;

class Bank {
private:
    vector<Account*> All_ACCOUNTS;

    Account* checkAccountPresent(long long acc_no);
    string generateDate_Time();
    void addAccountToDataBase(Account* ac);
    void createLogFile(Account* ac);
    void appendLogFile(long long acc_no, string Operation, long long amount, long long balance);

public:
    Bank();
    void addAccountToBank(Account* acc);
    void viewAllAcoount();
    bool bankCreateAccount(string newAccountHolderName);
    bool bankDeposite(long long acc_no);
    bool bankWithdraw(long long acc_no);
    bool bankCheckBalance(long long acc_no);
    bool bankGetAccountDetails(long long acc_no);
};

#endif
