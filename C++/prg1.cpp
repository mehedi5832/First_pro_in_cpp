#include <iostream>
#include <string>
using namespace std;

// Base class: Account
class Account {
protected:
    string name;
    int accountNumber;
    double balance;

public:
    // Constructor
    Account(string n, int accNum, double bal) : name(n), accountNumber(accNum), balance(bal) {}

    // Virtual function for depositing money
    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited: $" << amount << endl;
    }

    // Virtual function for withdrawing money
    virtual void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
        }
    }

    // Displaying account details
    virtual void displayAccountDetails() {
        cout << "Name: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }

    virtual ~Account() {}  // Virtual destructor for proper cleanup in derived classes
};

// Derived class: SavingsAccount
class SavingsAccount : public Account {
private:
    float interestRate;

public:
    // Constructor
    SavingsAccount(string n, int accNum, double bal, float intRate)
        : Account(n, accNum, bal), interestRate(intRate) {}

    // Method to calculate and apply interest
    void calculateInterest() {
        double interest = balance * (interestRate / 100);
        balance += interest;
        cout << "Interest added: $" << interest << endl;
    }

    // Overriding display method
    void displayAccountDetails() override {
        cout << "Account Type: Savings" << endl;
        Account::displayAccountDetails();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

// Derived class: CurrentAccount
class CurrentAccount : public Account {
public:
    // Constructor
    CurrentAccount(string n, int accNum, double bal) : Account(n, accNum, bal) {}

    // Overriding display method
    void displayAccountDetails() override {
        cout << "Account Type: Current" << endl;
        Account::displayAccountDetails();
    }
};

// Main function to demonstrate the use of inheritance
int main() {
    // Creating objects for savings and current accounts
    SavingsAccount savings("Mehedi Hassan", 101, 1000.00, 5.0);  // Interest rate = 5%
    CurrentAccount current("Masud Karim", 102, 5000.00);  // No interest

    // Perform operations on SavingsAccount
    cout << "\n--- Savings Account Operations ---\n";
    savings.displayAccountDetails();
    savings.deposit(200);  // Deposit
    savings.calculateInterest();  // Apply interest
    savings.withdraw(500);  // Withdraw
    savings.displayAccountDetails();  // Display updated details

    // Perform operations on CurrentAccount
    cout << "\n--- Current Account Operations ---\n";
    current.displayAccountDetails();
    current.deposit(500);  // Deposit
    current.withdraw(2000);  // Withdraw
    current.displayAccountDetails();  // Display updated details

    return 0;
}
