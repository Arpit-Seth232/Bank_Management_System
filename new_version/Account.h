#ifndef ACCOUNT_H
#define ACCOUNT_H

# include <bits/stdc++.h>
#include <chrono>

using namespace std;

class Account {
private:
    string name;
    long long account_no;
    long long balance;
    string date_time_of_creation;

public:
    string getAccountHolderName();
    long long getAccountNo();
    long long getBalance();
    string getOpeningDate();

    void setAccountHolderName(string name);
    void setAccountNo(long long acc_no);
    void setBalance(long long balance);
    void setOpeningDate(string time);

    void createAccount(string name, long long account_no, long long balance);
    void deposite(long long amount);
    bool withdraw(long long amount);
    void showAccountDetails();
};

#endif
