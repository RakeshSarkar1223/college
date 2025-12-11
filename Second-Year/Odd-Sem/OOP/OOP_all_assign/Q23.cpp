#include <iostream>
#include <cmath>
using namespace std;

class SavingsAccount {
private:
    char name[30];          // account holder name
    int accountNumber;      // unique account number
    double balance;         // current balance

    static int nextAccountNumber;   // generates unique account numbers
    static double interestRate;     // same for all accounts
    static const double MIN_BALANCE; // minimum allowed balance

public:
    // Constructor
    SavingsAccount(const char* accHolder, double initialBalance) {
        // Copy name manually
        int i = 0;
        while (accHolder[i] != '\0' && i < 29) {
            name[i] = accHolder[i];
            i++;
        }
        name[i] = '\0';  // null terminate

        accountNumber = ++nextAccountNumber;
        balance = (initialBalance >= MIN_BALANCE) ? initialBalance : MIN_BALANCE;
    }

    // Deposit money
    void deposit(double amount) {
        if (amount > 0)
            balance += amount;
        else
            cout << "Invalid deposit amount!\n";
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount <= 0)
            cout << "Invalid withdrawal amount!\n";
        else if (balance - amount < MIN_BALANCE)
            cout << "Withdrawal denied! Minimum balance Rs. " << MIN_BALANCE << " required.\n";
        else
            balance -= amount;
    }

    // Add one-year interest to balance and return the interest
    double addAnnualInterest() {
        double interest = (balance * interestRate) / 100.0;
        balance += interest;
        return interest;
    }

    // Display account info
    void display() const {
        cout << "Account No: " << accountNumber
             << " | Name: " << name
             << " | Balance: " << balance << endl;
    }

    // Static setter for interest rate
    static void setInterestRate(double rate) {
        interestRate = rate;
    }
};

// Initialize static members
int SavingsAccount::nextAccountNumber = 1000;
double SavingsAccount::interestRate = 4.5;
const double SavingsAccount::MIN_BALANCE = 1000.0;

//--------------------------------------
// Main function
//--------------------------------------
int main() {
    const int N = 10;
    SavingsAccount accounts[N] = {
        SavingsAccount("Amit", 15000),
        SavingsAccount("Rakesh", 23000),
        SavingsAccount("Suman", 18000),
        SavingsAccount("Kiran", 7500),   // will be set to 1000 (below min)
        SavingsAccount("Puja", 99000),
        SavingsAccount("Ravi", 25000),
        SavingsAccount("Mona", 40000),
        SavingsAccount("Vivek", 12500),
        SavingsAccount("Anita", 54000),
        SavingsAccount("Rohit", 35000)
    };

    cout << "Initial Account Details:\n";
    for (int i = 0; i < N; i++) {
        accounts[i].display();
    }

    double totalInterest = 0.0;

    // Add interest for all accounts
    for (int i = 0; i < N; i++) {
        totalInterest += accounts[i].addAnnualInterest();
    }

    cout << "\nAfter Adding One Year Interest:\n";
    for (int i = 0; i < N; i++) {
        accounts[i].display();
    }

    cout << "\nTotal interest paid to all accounts in one year: Rs. "
         << totalInterest << endl;

    return 0;
}
