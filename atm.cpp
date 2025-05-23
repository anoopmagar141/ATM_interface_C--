#include <iostream>
#include <limits> // For input validation
using namespace std;

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

    bool validateLogin(string enteredAccNum, string enteredPin) {
        return (enteredAccNum == accountNumber && enteredPin == pin);
    }

    void welcomeUser() {
        cout << "\nWelcome, " << accountHolder << "!\n";
    }

    void checkBalance() {
        cout << "\nYour current balance: $" << balance << endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "\n$" << amount << " deposited successfully." << endl;
            checkBalance();
        } else {
            cout << "\nInvalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "\n$" << amount << " withdrawn successfully." << endl;
            checkBalance();
        } else if (amount > balance) {
            cout << "\nInsufficient balance!" << endl;
        } else {
            cout << "\nInvalid withdrawal amount!" << endl;
        }
    }
};

// Function to validate numeric input
int getValidChoice() {
    int choice;
    while (true) {
        cout << "Choose an option: ";
        cin >> choice;

        if (cin.fail()) { 
            cin.clear();  // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid choice! Please enter a number.\n";
        } else {
            return choice;
        }
    }
}

int main() {
    string enteredAccNum, enteredPin;
    double amount;

    // Sample user account
    ATM userAccount("101", "John Doe", "1234", 5000.0);

    cout << "Enter Account Number: ";
    cin >> enteredAccNum;
    cout << "Enter PIN: ";
    cin >> enteredPin;

    if (!userAccount.validateLogin(enteredAccNum, enteredPin)) {
        cout << "\nIncorrect Account Number or PIN! Exiting...\n";
        return 0;
    }

    userAccount.welcomeUser();

    int choice;
    do {
        cout << "\nATM Menu:\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";

        choice = getValidChoice(); // Ensures only numbers are entered

        switch (choice) {
            case 1:
                userAccount.checkBalance();
                break;
            case 2:
                cout << "\nEnter amount to deposit: $";
                cin >> amount;
                userAccount.deposit(amount);
                break;
            case 3:
                cout << "\nEnter amount to withdraw: $";
                cin >> amount;
                userAccount.withdraw(amount);
                break;
            case 4:
                cout << "\nThank you for using the ATM. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice! Please select a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}
