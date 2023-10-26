









#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int age;
    int numCourses;
    string* courses;

public:
    // Dynamic constructor
    Student(string n, int a, int nc) : name(n), age(a), numCourses(nc) {
        courses = new string[numCourses];
    }

    // Destructor
    ~Student() {
        delete[] courses;
    }

    void setCourse(int index, string course) {
        if (index >= 0 && index < numCourses) {
            courses[index] = course;
        }
    }

    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    bool isEnrolled(string course) {
        for (int i = 0; i < numCourses; i++) {
            if (courses[i] == course) {
                return true;
            }
        }
        return false;
    }

    void displayDetails() {
        cout << "Student Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Courses: ";
        for (int i = 0; i < numCourses; i++) {
            cout << courses[i] << " ";
        }
        cout << endl << endl;
    }
};

int main() {
    string studentName;
    int studentAge, numCourses;
    cin >> studentName >> studentAge >> numCourses;

    Student s(studentName, studentAge, numCourses);

    for (int i = 0; i < numCourses; i++) {
        string courseName;
        cin >> courseName;
        s.setCourse(i, courseName);
    }

    s.displayDetails();

    string checkCourse;
    cin >> checkCourse;

    cout << "Is the student enrolled in " << checkCourse << "? ";
    if (s.isEnrolled(checkCourse)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
