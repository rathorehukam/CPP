


#include <iostream>
#include <vector>

class Main {
    int dayNumber;
public:
    Main(int d) : dayNumber(d) {
        determineAndPrintDay();
    }
    
    virtual ~Main() {}
    
    void determineAndPrintDay() {
        std::vector<std::string> days = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        if(dayNumber >= 1 && dayNumber <= 7) {
            std::cout << days[dayNumber - 1] << std::endl;
        } else {
            std::cout << "Invalid" << std::endl;
        }
    }
};

int main() {
    int d;
    std::cin >> d;
    Main obj(d);
    return 0;
}
