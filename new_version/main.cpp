#include <bits/stdc++.h>
#include "Bank.h"


int main() {
    Bank* bank = new Bank();
    char continue_process;

    do {
        cout << "\n-------------------- Welcome To Seth Bank Of India --------------------\n\n";
        cout << "\t\t1. Create Account\n";
        cout << "\t\t2. Deposite Money\n";
        cout << "\t\t3. Withdraw Money\n";
        cout << "\t\t4. Check Balance\n";
        cout << "\t\t5. Check AccountDetails\n";
        cout << "\t\t6. Exit\n\n";
        cout << "-----------------------------------------------------------------------\n\n";

        int option;
        cout << "Enter the no. of operation from 1-6 : ";
        cin >> option;
        cout << endl;

        switch (option) {
            case 1: {
                cout << "Enter the name of account holder : ";
                string name;
                cin.ignore();
                getline(cin, name);
                if (!bank->bankCreateAccount(name))
                    cout << "Account Creation Failed\n\n";
                else
                    cout << "Account Created Successfully\n\n";
                break;
            }

            case 2: {
                cout << "Enter the account no. : ";
                long long account_no;
                cin >> account_no;
                cout << endl;
                if (!bank->bankDeposite(account_no))
                    cout << "Amount Deposite Failed\n\n";
                else
                    cout << "Amount Deposited Successfully\n\n";
                break;
            }

            case 3: {
                cout << "Enter the account no. : ";
                long long account_no;
                cin >> account_no;
                cout << endl;
                if (!bank->bankWithdraw(account_no))
                    cout << "Amount Withdrawal Failed\n\n";
                else
                    cout << "Amount Withdrawal Successfully\n\n";
                break;
            }

            case 4: {
                cout << "Enter the account no. : ";
                long long account_no;
                cin >> account_no;
                cout << endl;
                if (!bank->bankCheckBalance(account_no))
                    cout << "Balance Check Failed\n\n";
                else
                    cout << "Balance Checked Successfully\n\n";
                break;
            }

            case 5: {
                cout << "Enter the account no. : ";
                long long account_no;
                cin >> account_no;
                cout << endl;
                if (!bank->bankGetAccountDetails(account_no))
                    cout << "Details Fetch Failed\n\n";
                else
                    cout << "Details Fetched Successfully\n\n";
                break;
            }

            case 6:
                return 0;

            default:
                cout << "Invalid operation selected\n\n";
        }

        cout << "Do you want to continue [Y/N] : ";
        cin >> continue_process;
        cout << endl;

    } while (continue_process == 'y' || continue_process == 'Y');

    return 0;
}
