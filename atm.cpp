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
    