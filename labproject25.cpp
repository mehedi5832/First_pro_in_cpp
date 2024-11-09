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
    // Constructor to initialize the account
    SavingsAccount(int accNum, string accName, double bal, double rate)
        : accountNumber(accNum), accountHolderName(accName), balance(bal), interestRate(rate) {}

    // Method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    // Method to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        }
    }

    // Method to calculate and add interest
    void addInterest() {
        double interest = balance * (interestRate / 100);
        balance += interest;
    }

    // Method to get account details (for internal use)
    string getAccountDetails() const {
        return "Account Number: " + to_string(accountNumber) + "\n" +
               "Account Holder: " + accountHolderName + "\n" +
               "Balance: $" + to_string(balance) + "\n" +
               "Interest Rate: " + to_string(interestRate) + "%\n";
    }

    // Getter for balance
    double getBalance() const {
        return balance;
    }

    // Setter for balance (optional in encapsulation)
    void setBalance(double newBalance) {
        balance = newBalance;
    }
};

int main() {
    // Create a SavingsAccount object with predefined values (no user input)
    SavingsAccount mySavings(101, "Mehedi Hassan", 1000.00, 5.0); // Account number, name, initial balance, interest rate

    // Perform a deposit operation
    mySavings.deposit(200.00); // Deposit $200

    // Perform a withdrawal operation
    mySavings.withdraw(150.00); // Withdraw $150

    // Add interest to the balance
    mySavings.addInterest(); // Apply 5% interest

    // Display the updated account details (this part is not UI, but internal code logic)
    string details = mySavings.getAccountDetails();
    cout << details << endl;

    return 0;
}
