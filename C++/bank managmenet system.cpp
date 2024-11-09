#include <iostream>
#include <string>
using namespace std;

// Base class for bank account
class Account {
protected:
    string name;
    int accno;
    string atype;

public:
    Account() : name(""), accno(0), atype("") {}

    void getAccountDetails() {
        cout << "\nEnter Customer Name: ";
        cin.ignore(); // To ignore any leftover newline character from previous input
        getline(cin, name);
        cout << "Enter Account Number: ";
        cin >> accno;
        cout << "Enter Account Type (Saving/Current): ";
        cin >> atype;
    }

    void displayDetails() const {
        cout << "\nCustomer Name: " << name;
        cout << "\nAccount Number: " << accno;
        cout << "\nAccount Type: " << atype;
    }
};

// Derived class for current account
class CurrentAccount : public Account {
private:
    float balance;

public:
    CurrentAccount() : balance() {}

    void deposit() {
        float depositAmount;
        cout << "\nEnter amount to Deposit: ";
        cin >> depositAmount;
        balance += depositAmount;
        cout << "\nDeposit successful!";
    }

    void withdraw() {
        float withdrawAmount;
        cout << "\nBalance: " << balance;
        cout << "\nEnter amount to Withdraw: ";
        cin >> withdrawAmount;
        if (balance - withdrawAmount >= 1000) {
            balance -= withdrawAmount;
            cout << "\nWithdrawal successful! New Balance: " << balance;
        } else {
            cout << "\nInsufficient Balance!";
        }
    }

    void displayBalance() const {
        cout << "\nCurrent Balance: " << balance;
    }
};

// Derived class for saving account
class SavingAccount : public Account {
private:
    float sav_balance;

public:
    SavingAccount() : sav_balance(0.0f) {}

    void deposit() {
        float depositAmount;
        cout << "\nEnter amount to Deposit: ";
        cin >> depositAmount;
        sav_balance += depositAmount;
        float interest = (sav_balance * 2) / 100;
        sav_balance += interest;
        cout << "\nDeposit successful! New Balance (with interest): " << sav_balance;
    }

    void withdraw() {
        float withdrawAmount;
        cout << "\nBalance: " << sav_balance;
        cout << "\nEnter amount to Withdraw: ";
        cin >> withdrawAmount;
        if (sav_balance - withdrawAmount >= 500) {
            sav_balance -= withdrawAmount;
            cout << "\nWithdrawal successful! New Balance: " << sav_balance;
        } else {
            cout << "\nInsufficient Balance!";
        }
    }

    void displayBalance() const {
        cout << "\nSaving Balance: " << sav_balance;
    }
};

int main() {
    char type;
    int choice;

    cout << "\nEnter S for Saving account and C for Current account: ";
    cin >> type;

    if (type == 's' || type == 'S') {
        SavingAccount s1;
        s1.getAccountDetails();
        do {
            cout << "\nChoose Your Choice" << endl;
            cout << "1) Deposit" << endl;
            cout << "2) Withdraw" << endl;
            cout << "3) Display Balance" << endl;
            cout << "4) Display with Full Details" << endl;
            cout << "5) Exit" << endl;
            cout << "Enter Your choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    s1.deposit();
                    break;
                case 2:
                    s1.withdraw();
                    break;
                case 3:
                    s1.displayBalance();
                    break;
                case 4:
                    s1.displayDetails();
                    s1.displayBalance();
                    break;
                case 5:
                    cout << "\nExiting...";
                    break;
                default:
                    cout << "\nInvalid choice, please try again.";
            }
        } while (choice != 5);
    } else if (type == 'c' || type == 'C') {
        CurrentAccount c1;
        c1.getAccountDetails();
        do {
            cout << "\nChoose Your Choice" << endl;
            cout << "1) Deposit" << endl;
            cout << "2) Withdraw" << endl;
            cout << "3) Display Balance" << endl;
            cout << "4) Display with Full Details" << endl;
            cout << "5) Exit" << endl;
            cout << "Enter Your choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    c1.deposit();
                    break;
                case 2:
                    c1.withdraw();
                    break;
                case 3:
                    c1.displayBalance();
                    break;
                case 4:
                    c1.displayDetails();
                    c1.displayBalance();
                    break;
                case 5:
                    cout << "\nExiting...";
                    break;
                default:
                    cout << "\nInvalid choice, please try again.";
            }
        } while (choice != 5);
    } else {
        cout << "\nInvalid Account Selection";
    }

    cout << "\nThank you for banking with us!";
    return 0;
}
