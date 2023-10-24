







#include <iostream>
#include <string>

class Course {
private:
    std::string name;
    Course* prerequisite;

public:
    Course(const std::string& courseName) : name(courseName), prerequisite(nullptr) {}

    ~Course() {
        delete prerequisite;
    }

    void setPrerequisite(Course* prereq) {
        prerequisite = prereq;
    }

    std::string getName() const {
        return name;
    }

    void display(int level = 0) const {
        for (int i = 0; i < level; ++i) {
            std::cout << "  ";
        }
        if (level > 0) {
            std::cout << "Prerequisite: ";
        }
        std::cout << "- " << name << std::endl;

        if (prerequisite) {
            prerequisite->display(level + 1);
        }
    }
};

int main() {
    std::string courseName;
    char hasPrerequisite;

    std::getline(std::cin, courseName);
    Course* currentCourse = new Course(courseName);
    Course* root = currentCourse;

    while (true) {
        std::cin >> hasPrerequisite;
        std::cin.ignore();

        if (hasPrerequisite == 'y' || hasPrerequisite == 'Y') {
            std::getline(std::cin, courseName);
            Course* prereq = new Course(courseName);
            currentCourse->setPrerequisite(prereq);
            currentCourse = prereq;
        } else {
            break;
        }
    }

    std::cout << "Course Prerequisites:" << std::endl;
    root->display();

    delete root;
    return 0;
}
