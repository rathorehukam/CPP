








#include <iostream>
#include <iomanip>

using namespace std;

class Employee {
private:
    string name;
    string id;
    float monthlySalary;

public:
    Employee(const string& name, const string& id, float monthlySalary)
        : name(name), id(id), monthlySalary(monthlySalary) {}

    string getName() const {
        return name;
    }

    string getId() const {
        return id;
    }

    float getMonthlySalary() const {
        return monthlySalary;
    }

    float getAnnualSalary() const {
        return 12 * monthlySalary;
    }

    void giveRaise(float percentage) {
        monthlySalary += (percentage / 100) * monthlySalary;
    }

    void display() const {
        cout << "Employee Name: " << name << endl;
        cout << "Employee ID: " << id << endl;
        cout << "Monthly Salary: $" << fixed << setprecision(2) << monthlySalary << endl;
        cout << "Annual Salary: $" << getAnnualSalary() << endl;
    }
};

int main() {
    string name, id;
    float monthlySalary, raisePercentage;

    // Read input
    getline(cin, name);
    getline(cin, id);
    cin >> monthlySalary;
    cin >> raisePercentage;

    Employee employee(name, id, monthlySalary);

    employee.display();

    employee.giveRaise(raisePercentage);
    employee.display();

    return 0;
}
