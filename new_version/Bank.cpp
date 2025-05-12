#include "Bank.h"

Bank::Bank() {
    ifstream inFile("./data.json");
    json customer;
    inFile >> customer;

    for (auto c : customer) {
        Account* ac = new Account;
        ac->setAccountHolderName(c["name"]);
        ac->setAccountNo(c["account_no"]);
        ac->setBalance(c["balance"]);
        ac->setOpeningDate(c["opening_date"]);
        All_ACCOUNTS.push_back(ac);
    }
}

Account* Bank::checkAccountPresent(long long acc_no) {
    for (auto& acc : All_ACCOUNTS)
        if (acc->getAccountNo() == acc_no)
            return acc;
    return nullptr;
}

string Bank::generateDate_Time() {
    auto now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);
    return string(ctime(&currentTime)).substr(0, 24);
}

void Bank::addAccountToDataBase(Account* ac) {
    ofstream outFile("./Bank.txt", ios::app);
    if (outFile.is_open()) {
        outFile << "\n\t\t\t" << ac->getAccountNo()
                << "\t\t\t\t\t" << ac->getAccountHolderName()
                << "\t\t\t\t\t\topen\t\t\t  " << ac->getOpeningDate()
                << "\t\t\t\t" << ac->getBalance();
        outFile.close();
    }
}

void Bank::createLogFile(Account* ac) {
    string nameOfFile = "./account_" + to_string(ac->getAccountNo()) + ".txt";
    ofstream outFile(nameOfFile, ios::app);
    if (outFile.is_open()) {
        outFile << "Account_Holder_Name : " << ac->getAccountHolderName() << "\n";
        outFile << "Account_No. : " << ac->getAccountNo() << "\n\n";
        outFile << "-------------------------------------------------------------------------------------------------------------------------------------------\n";
        outFile << "      |               Date_&_Time             |               Operation               |               Account_Balance             |\n";
        outFile << "-------------------------------------------------------------------------------------------------------------------------------------------\n";
        outFile << "\t\t    " << ac->getOpeningDate()
                << "\t\t\t  open & deposite (" << ac->getBalance()
                << ")\t\t\t\t\t" << ac->getBalance() << "\n";
        outFile.close();
    }
}

void Bank::appendLogFile(long long acc_no, string Operation, long long amount, long long balance) {
    string nameOfFile = "./account_" + to_string(acc_no) + ".txt";
    string Date_Time = generateDate_Time();
    ofstream outFile(nameOfFile, ios::app);
    if (outFile.is_open()) {
        if (Operation == "deposite")
            outFile << "\t\t    " << Date_Time << "\t\t\t\tDeposite (" << amount << ")\t\t\t\t\t\t" << balance << "\n";
        else if (Operation == "withdraw")
            outFile << "\t\t    " << Date_Time << "\t\t\t\tWithdraw (" << amount << ")\t\t\t\t\t\t" << balance << "\n";
        else if (Operation == "getDetails")
            outFile << "\t\t    " << Date_Time << "\t\t\t\tFetched Details\t\t\t\t\t\t" << balance << "\n";
        else
            outFile << "\t\t    " << Date_Time << "\t\t\t\tFetched Balance\t\t\t\t\t\t" << balance << "\n";
    }
}

void Bank::addAccountToBank(Account* acc) {
    All_ACCOUNTS.push_back(acc);
    ifstream inFile("./data.json");
    json customers;
    inFile >> customers;

    ofstream outFile("./data.json");
    json c;
    c["name"] = acc->getAccountHolderName();
    c["account_no"] = acc->getAccountNo();
    c["balance"] = acc->getBalance();
    c["opening_date"] = acc->getOpeningDate();
    customers.push_back(c);
    outFile << customers.dump(4);
}

void Bank::viewAllAcoount() {
    for (auto& acc : All_ACCOUNTS)
        acc->showAccountDetails();
}

bool Bank::bankCreateAccount(string newAccountHolderName) {
    long long newAccountNo = All_ACCOUNTS.empty() ? 1000 : All_ACCOUNTS.back()->getAccountNo() + 1;
    cout << "Enter the first amount to be deposited : ";
    long long amount;
    cin >> amount;
    cout << endl;

    if (amount < 0) {
        cout << "Invalid amount entered" << endl;
        return false;
    }

    Account* ac1 = new Account;
    ac1->createAccount(newAccountHolderName, newAccountNo, amount);
    addAccountToBank(ac1);
    addAccountToDataBase(ac1);
    createLogFile(ac1);

    cout << "--------- Your Account Details are : ---------" << endl << endl;
    ac1->showAccountDetails();
    return true;
}

bool Bank::bankDeposite(long long acc_no) {
    Account* ac = checkAccountPresent(acc_no);
    if (!ac) {
        cout << "Account Not Found" << endl;
        return false;
    }

    cout << "Enter the amount : ";
    long long amt;
    cin >> amt;
    cout << endl;

    if (amt <= 0) {
        cout << "Invalid Amount Entered" << endl;
        return false;
    }

    ac->deposite(amt);

    ifstream inFile("./data.json");
    json customer;
    inFile >> customer;

    for (auto& c : customer) {
        if (acc_no == c["account_no"]) {
            c["balance"] = ac->getBalance();
            break;
        }
    }

    ofstream outFile("./data.json");
    outFile << customer.dump(4);
    appendLogFile(acc_no, "deposite", amt, ac->getBalance());

    return true;
}

bool Bank::bankWithdraw(long long acc_no) {
    Account* ac = checkAccountPresent(acc_no);
    if (!ac) {
        cout << "Account Not Found" << endl;
        return false;
    }

    cout << "Enter the amount : ";
    long long amt;
    cin >> amt;
    cout << endl;

    if (ac->withdraw(amt)) {
        ifstream inFile("./data.json");
        json customer;
        inFile >> customer;

        for (auto& c : customer) {
            if (acc_no == c["account_no"]) {
                c["balance"] = ac->getBalance();
                break;
            }
        }

        ofstream outFile("./data.json");
        outFile << customer.dump(4);
        appendLogFile(acc_no, "withdraw", amt, ac->getBalance());
        return true;
    }
    return false;
}

bool Bank::bankCheckBalance(long long acc_no) {
    Account* ac = checkAccountPresent(acc_no);
    if (!ac) {
        cout << "Account Not Found" << endl;
        return false;
    }

    cout << "Your account's current balance is : " << ac->getBalance() << endl << endl;
    appendLogFile(acc_no, "getBalance", 0, ac->getBalance());
    return true;
}

bool Bank::bankGetAccountDetails(long long acc_no) {
    Account* ac = checkAccountPresent(acc_no);
    if (!ac) {
        cout << "Account Not Found" << endl;
        return false;
    }

    cout << "------- Your account's details are : --------" << endl << endl;
    ac->showAccountDetails();
    appendLogFile(acc_no, "getDetails", 0, ac->getBalance());
    return true;
}
