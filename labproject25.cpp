#include <iostream>
#include <string>

using namespace std;

class SavingsAccount {
private:
    int accountNumber;
    string accountHolderName;
    double balance;
    double interestRate;

public:
    SavingsAccount(int accNum, string accName, double bal, double rate)
        : accountNumber(accNum), accountHolderName(accName), balance(bal), interestRate(rate) {}

    // Method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        }
    }
    void addInterest() {
        double interest = balance * (interestRate / 100);
        balance += interest;
    }
    string getAccountDetails() const {
        return "Account Number: " + to_string(accountNumber) + "\n" +
               "Account Holder: " + accountHolderName + "\n" +
               "Balance: $" + to_string(balance) + "\n" +
               "Interest Rate: " + to_string(interestRate) + "%\n";
    }
    double getBalance() const {
        return balance;
    }
    void setBalance(double newBalance) {
        balance = newBalance;
    }
};

int main() {
    SavingsAccount mySavings(101, "Mehedi Hassan", 1000.00, 5.0);
    mySavings.deposit(200.00); 
    mySavings.withdraw(150.00);
    mySavings.addInterest();
    
    string details = mySavings.getAccountDetails();
    cout << details << endl;

    return 0;
}
