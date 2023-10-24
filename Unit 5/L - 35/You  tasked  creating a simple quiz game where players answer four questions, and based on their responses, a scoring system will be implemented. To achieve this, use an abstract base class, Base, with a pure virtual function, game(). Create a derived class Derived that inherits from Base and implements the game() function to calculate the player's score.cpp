







#include <iostream>
#include <vector>

class Base {
public:
    virtual int game(const std::vector<char>& answers) = 0;
};

class Derived : public Base {
public:
    int game(const std::vector<char>& answers) override {
        int score = 0;
        for (char ans : answers) {
            if (ans >= 'A' && ans <= 'Z') {
                score += 10;
            } else if (ans >= 'a' && ans <= 'z') {
                score -= 5;
            }
        }
        return score;
    }
};

int main() {
    std::vector<char> answers(4);

    for (int i = 0; i < 4; ++i) {
        std::cin >> answers[i];
    }

    Derived player;
    int totalScore = player.game(answers);

    std::cout << "Score : " << totalScore << std::endl;

    return 0;
}
