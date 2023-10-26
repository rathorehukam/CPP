







#include <iostream>
#include <cstring>

using namespace std;

class StringSearch {
private:
    string mainString;

public:
    StringSearch(const string &str) : mainString(str) {}

    bool operator/(const string &subString) {
        return mainString.find(subString) != string::npos;
    }
};

int main() {
    string mainText, subText;
    getline(cin, mainText);
    getline(cin, subText);

    StringSearch search(mainText);
    if (search / subText) {
        cout << "Substring is present" << endl;
    } else {
        cout << "substring is not present" << endl;
    }

    return 0;
}
