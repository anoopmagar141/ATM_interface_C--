#include <iostream>
using namespace std;

int main() {
    cout << "Welcome to the ATM System!\n";
    return 0;
}
class ATM {
    private:
        string accountNumber;
        string pin;
        string accountHolder;
        double balance;
    
    public:
        ATM(string accNum, string accHolder, string userPin, double initialBalance) {
            accountNumber = accNum;
            accountHolder = accHolder;
            pin = userPin;
            balance = initialBalance;
        }
    };
    void checkBalance() {
        cout << "\nYour current balance: $" << balance << endl;
    }
    
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "\n$" << amount << " deposited successfully.\n";
            checkBalance();
        } else {
            cout << "\nInvalid deposit amount!\n";
        }
    }
    
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "\n$" << amount << " withdrawn successfully.\n";
            checkBalance();
        } else if (amount > balance) {
            cout << "\nInsufficient balance!\n";
        } else {
            cout << "\nInvalid withdrawal amount!\n";
        }
    }
    bool validateLogin(string enteredAccNum, string enteredPin) {
        return (enteredAccNum == accountNumber && enteredPin == pin);
    }
    
    void welcomeUser() {
        cout << "\nWelcome, " << accountHolder << "!\n";
    }
    