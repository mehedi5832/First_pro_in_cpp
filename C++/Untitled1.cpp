#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
    private:
    int accountNumber;
    string accountHolderName;
    double balance;

    public:
     // Constructor to initialize the account
    BankAccount(string name, int accNum, double initialBalance)
    {
        accountHolderName = name;
        accountNumber = accNum;
        if (initialBalance >= 0) {
            balance = initialBalance;
        } else {
            balance = 0;
            cout << "Initial balance cannot be negative. Balance set to 0." << endl;
        }
    }
       //deposit money
    void deposit (double ammount)
    {
        if (ammount > 0)
        {
            balance += ammount ;
            cout << "deposited: $" << " New Balance: $" << balance << endl;

        }else
        {
            cout << "Invalid deposit amount!"<< endl;
        }
    }
    // withdraw money
    void withdraw(double amount)
    {
         if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawn: $" << amount << ". Remaining Balance: $" << balance << endl;
        } else
         {
            cout << "Invalid withdraw amount or insufficient balance!" << endl;
        }
    }
    //check Balance
    double getBAlance() const
    {
        return balance;
    }
    //display accountinfo

    void displayAccountDetails() const
    {
       cout << "Account Holder: "<< accountHolderName << endl;
       cout << "Account Number: "<< accountNumber << endl;
       cout << "Balance: $"<< balance << endl;
    }
};

int main()
{
    //creat a new bankaccount with initial balance
    BankAccount myAccount("Mehedi Hassan", 123456, 500.00);
    cout << "Initial Account details: " << endl;
    myAccount.displayAccountDetails();
    cout << endl;

    //deposite money
    myAccount.deposit(200);
    cout << endl;

    myAccount.withdraw(1450);
    cout << endl;

    cout << "final Account details: " << endl;
    myAccount.displayAccountDetails();

    return 0;
}
