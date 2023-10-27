




#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int age;
    int courseCount;
    std::string* courses;

public:
 
    Student(std::string nm, int ag, int n) : name(nm), age(ag), courseCount(n) {
        courses = new std::string[n];
    }

    void setCourse(int index, std::string courseName) {
        if (index >= 0 && index < courseCount) {
            courses[index] = courseName;
        }
    }
    bool isEnrolled(std::string courseName) {
        for (int i = 0; i < courseCount; i++) {
            if (courses[i] == courseName) {
                return true;
            }
        }
        return false;
    }

    void displayDetails() {
        std::cout << "Student Details:" << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Courses: ";
        for (int i = 0; i < courseCount; i++) {
            std::cout << courses[i] << (i == courseCount - 1 ? "\n" : " ");
        }
    }

    ~Student() {
        delete[] courses;
    }
};

int main() {
    std::string name, course, checkCourse;
    int age, n;

    std::getline(std::cin, name);
    std::cin >> age;
    std::cin >> n;
    std::cin.ignore(); 

    Student student(name, age, n);
    
    for (int i = 0; i < n; i++) {
        std::getline(std::cin, course);
        student.setCourse(i, course);
    }

    student.displayDetails();

    std::getline(std::cin, checkCourse);
    std::cout << "\nIs the student enrolled in " << checkCourse << "? ";
    if (student.isEnrolled(checkCourse)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
