#include "Account.h"

string Account::getAccountHolderName() { return name; }
long long Account::getAccountNo() { return account_no; }
long long Account::getBalance() { return balance; }
string Account::getOpeningDate() { return date_time_of_creation; }

void Account::setAccountHolderName(string name) { this->name = name; }
void Account::setAccountNo(long long acc_no) { this->account_no = acc_no; }
void Account::setBalance(long long balance) { this->balance = balance; }
void Account::setOpeningDate(string time) { this->date_time_of_creation = time; }

void Account::createAccount(string name, long long account_no, long long balance) {
    auto now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);
    auto date_time = ctime(&currentTime);
    this->name = name;
    this->account_no = account_no;
    this->balance = balance;
    this->date_time_of_creation = string(date_time).substr(0, 24);
}

void Account::deposite(long long amount) {
    this->balance += amount;
    cout << "The current balance is : " << this->balance << endl << endl;
}

bool Account::withdraw(long long amount) {
    if (amount <= 0 || amount > this->balance) {
        cout << "Invalid amount entered" << endl;
        return false;
    }
    this->balance -= amount;
    cout << "The current balance is : " << this->balance << endl << endl;
    return true;
}

void Account::showAccountDetails() {
    cout << "Account Holder Name : " << name << endl;
    cout << "Account No. : " << account_no << endl;
    cout << "Account Balance : " << balance << endl;
    cout << "Account Opening Date and Time : " << date_time_of_creation << endl;
}
