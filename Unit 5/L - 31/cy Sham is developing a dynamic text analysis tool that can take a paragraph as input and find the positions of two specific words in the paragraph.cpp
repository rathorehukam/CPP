





#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int findWordPosition(const string& paragraph, const string& word) {
    istringstream iss(paragraph);
    string temp;
    int position = 0;

    while (iss >> temp) {
        if (temp == word) {
            return position;
        }
        position++;
    }
    
    return -1;
}

int main() {
    string* paragraph = new string;
    string* word1 = new string;
    string* word2 = new string;
    getline(cin, *paragraph);
    cin >> *word1;
    cin >> *word2;
    int pos1 = findWordPosition(*paragraph, *word1);
    if (pos1 != -1) {
        cout << "First occurrence of \"" << *word1 << "\" found at position: " << pos1 +1 << endl;
    } else {
        cout << "Word \"" << *word1 << "\" not found in the paragraph." << endl;
    }
    int pos2 = findWordPosition(*paragraph, *word2);
    if (pos2 != -1) {
        cout << "First occurrence of \"" << *word2 << "\" found at position: " << pos2 +1<< endl;
    } else {
        cout << "Word \"" << *word2 << "\" not found in the paragraph." << endl;
    }

    delete paragraph;
    delete word1;
    delete word2;

    return 0;
}
