










#include <iostream>
using namespace std;

class QuizGame {
public:
    virtual void game() = 0;  
};

class StudentScore : public QuizGame {
public:
    void game() override {
        char ch;
        int score = 0;

        for (int i = 0; i < 4; ++i) {
            cin >> ch;

            if (ch >= 'A' && ch <= 'Z') {
                score += 10;
            }

            else if (ch >= 'a' && ch <= 'z') {
                score -= 5;
            }
        }
        cout << "Score : " << score << endl;
    }
};

int main() {
    StudentScore student;
    student.game();
    return 0;
}
