








#include <iostream>
#include <iomanip>

using namespace std;

bool isLeapYear(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    return year % 4 == 0;
}

int getDaysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        case 2: return isLeapYear(year) ? 29 : 28;
        default: return 0;
    }
}

int getDayOfWeek(int day, int month, int year) {
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    if (month < 3) year -= 1;
    return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
}

int main() {
    int month, year;
    cin >> month >> year;

    if (month < 1 || month > 12 || year < 0) {
        cout << "Invalid input. Please enter a valid month (1-12) and year.";
        return 0;
    }

    int days = getDaysInMonth(month, year);
    int firstDay = (getDayOfWeek(1, month, year) + 6) % 7;

    char* header = new char[26];
    sprintf(header, "    %d/%d Calendar    ", month, year);

    cout << "=========================" << endl;
    cout << header << endl;
    cout << "=========================" << endl;
    cout << "Mon Tue Wed Thu Fri Sat Sun" << endl;
    
    int space = firstDay * 4;
    for (int i = 1; i <= days; i++) {
        if ((i + firstDay - 1) % 7 == 0 && i != 1) cout << endl;
        cout << setw(space) << i;
        space = 4;
    }
    cout << endl << endl;

    delete[] header;

    return 0;
}
