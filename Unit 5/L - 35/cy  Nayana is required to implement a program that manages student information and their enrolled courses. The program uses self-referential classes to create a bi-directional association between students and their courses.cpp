




#include<bits/stdc++.h>
using namespace std;

class Student; 

class Course {
private:
    string courseName;
    int grade;
    Student* student; 
public:
    Course(string name, int g, Student* s): courseName(name), grade(g), student(s) {}

    string getCourseName() {
        return courseName;
    }

    int getGrade() {
        return grade;
    }
};

class Student {
private:
    string studentName;
    vector<Course> courses; 

public:
    Student(string name): studentName(name) {}

    void enrollCourse(string courseName, int grade) {
        courses.push_back(Course(courseName, grade, this));
    }

    void display() {
        cout << "Name: " << studentName << endl;
        cout << "Courses:" << endl;
        for (Course& c : courses) {
            cout << "  " << c.getCourseName() << ": " << c.getGrade() << endl;
        }
    }
};

int main() {
    string studentName, courseName;
    int numCourses, grade;

    getline(cin, studentName);
    Student s(studentName);

    cin >> numCourses;
    cin.ignore(); 
    for (int i = 0; i < numCourses; i++) {
        getline(cin, courseName); 
        cin >> grade;
        cin.ignore();
        s.enrollCourse(courseName, grade);
    }

    s.display();
    return 0;
}
