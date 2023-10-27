









#include <iostream>
#include <iomanip>
class Account {
public:
    virtual void display() const = 0;
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
};

class savingsAccount : public Account {
private:
    int accno;
    std::string name;
    double balance;

public:
    savingsAccount(int n, std::string nm, double bal) : accno(n), name(nm), balance(bal) {}
    
    void display() const override {
        std::cout << accno << " " << name << " " << std::fixed << std::setprecision(2) << balance << std::endl;
    }

    void deposit(double amount) override {
        balance += amount;
        std::cout << "Balance after deposit: " << std::fixed << std::setprecision(2) << balance << std::endl;
    }

    void withdraw(double amount) override {
        if (balance < amount) {
            std::cout << "Insufficient balance for withdrawal!" << std::endl;
        } else {
            balance -= amount;
            std::cout << "Balance after withdrawal: " << std::fixed << std::setprecision(2) << balance << std::endl;
        }
    }
};

int main() {
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        int accno;
        std::string name;
        double balance;
        std::cin >> accno >> name >> balance;
        savingsAccount sa(accno, name, balance);
        sa.display();

        int option;
        std::cin >> option;

        if (option == 2) {
            double amount;
            std::cin >> amount;
            sa.deposit(amount);
        } else if (option == 3) {
            double amount;
            std::cin >> amount;
            sa.withdraw(amount);
        } else {
            std::cout << "Invalid option" << std::endl;
        }

        sa.display();
    }

    return 0;
}
