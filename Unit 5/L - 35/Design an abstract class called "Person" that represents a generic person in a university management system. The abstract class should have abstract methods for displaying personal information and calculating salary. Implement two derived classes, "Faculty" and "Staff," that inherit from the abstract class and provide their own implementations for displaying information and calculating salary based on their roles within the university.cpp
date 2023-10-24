









#include <iostream>
#include <string>
#include <iomanip>

class Person {
protected:
    std::string name;
    int age;
public:
    Person(std::string n, int a) : name(n), age(a) {}
    virtual void displayInfo() = 0;
    virtual void calculateSalary() = 0;
};

class Faculty : public Person {
private:
    double teachingHours;
    double hourlyRate;
public:
    Faculty(std::string n, int a, double hours, double rate) : Person(n, a), teachingHours(hours), hourlyRate(rate) {}

    void displayInfo() override {
        std::cout << "Faculty Information:" << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Teaching Hours: " << teachingHours << std::endl;
    }

    void calculateSalary() override {
        std::cout << "Salary: " << std::fixed << std::setprecision(2) << teachingHours * hourlyRate << std::endl;
    }
};

class Staff : public Person {
private:
    double monthlyPay;
public:
    Staff(std::string n, int a, double pay) : Person(n, a), monthlyPay(pay) {}

    void displayInfo() override {
        std::cout << "Staff Information:" << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
    }

    void calculateSalary() override {
        std::cout << "Salary: " << std::fixed << std::setprecision(2) << monthlyPay << std::endl;
    }
};

int main() {
    std::string fName, sName;
    int fAge, sAge;
    double fHours, fRate, sPay;

    std::cin >> fName >> fAge >> fHours >> fRate;
    std::cin >> sName >> sAge >> sPay;

    Faculty facultyMember(fName, fAge, fHours, fRate);
    Staff staffMember(sName, sAge, sPay);

    facultyMember.displayInfo();
    facultyMember.calculateSalary();

    std::cout << std::endl;

    staffMember.displayInfo();
    staffMember.calculateSalary();

    return 0;
}
