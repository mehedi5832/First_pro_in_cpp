#include <iostream>
#include <string>

using namespace std;

class Account {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    Account(int accNum, string accName, double bal) : accountNumber(accNum), accountHolderName(accName), balance(bal) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << ". New Balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << ". New Balance: " << balance << endl;
        } else {
            cout << "Invalid withdraw amount or insufficient balance!" << endl;
        }
    }

    virtual void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }

    double getBalance() const {
        return balance;
    }

    void setBalance(double newBalance) {
        balance = newBalance;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(int accNum, const string& accName, double bal, double rate)
        : Account(accNum, accName, bal), interestRate(rate) {}

    void addInterest() {
        double interest = getBalance() * (interestRate / 100);
        setBalance(getBalance() + interest);
        cout << "Interest added: " << interest << ". New Balance: " << getBalance() << endl;
    }

    void display() const override {
        Account::display();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

int main() {
    int accNum;
    string accName;
    double initialBalance;
    double interestRate;

    cout << "Enter Account Number: ";
    cin >> accNum;
    cout << "Enter Account Holder Name: ";
    cin.ignore();
    getline(cin, accName);
    cout << "Enter Initial Balance: ";
    cin >> initialBalance;
    cout << "Enter Interest Rate (%): ";
    cin >> interestRate;

    SavingsAccount mySavings(accNum, accName, initialBalance, interestRate);

    mySavings.display();
    cout << endl;

    double depositAmount;
    cout << "Enter amount to deposit: ";
    cin >> depositAmount;
    mySavings.deposit(depositAmount);
    cout << endl;

    double withdrawAmount;
    cout << "Enter amount to withdraw: ";
    cin >> withdrawAmount;
    mySavings.withdraw(withdrawAmount);
    cout << endl;

    mySavings.addInterest();
    cout << endl;

    mySavings.display();

    return 0;
}

