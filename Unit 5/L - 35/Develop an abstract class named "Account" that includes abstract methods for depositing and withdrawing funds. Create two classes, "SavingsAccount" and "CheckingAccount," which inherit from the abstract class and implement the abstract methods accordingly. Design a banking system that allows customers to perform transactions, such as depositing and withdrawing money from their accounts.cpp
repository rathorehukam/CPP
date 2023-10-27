





#include <iostream>
using namespace std;

class Account {
protected:
    double balance;
public:
    Account() : balance(0) {}
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void displayBalance() = 0;
};
class SavingsAccount : public Account {
public:
    void deposit(double amount) {
        balance += amount;
        cout << "Amount deposited: " << amount << endl;
    }
    
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Amount withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient funds. Withdrawal canceled." << endl;
        }
    }

    void displayBalance() {
        cout << "Savings Account Balance: " << balance << endl;
    }
};

int main() {
    SavingsAccount account;
    int choice;
    double amount;

    while (true) {
        cin >> choice;
        switch (choice) {
            case 1: 
                cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                cin >> amount;
                account.withdraw(amount);
                break;
            case 3: 
                account.displayBalance();
                break;
            case 0: 
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
