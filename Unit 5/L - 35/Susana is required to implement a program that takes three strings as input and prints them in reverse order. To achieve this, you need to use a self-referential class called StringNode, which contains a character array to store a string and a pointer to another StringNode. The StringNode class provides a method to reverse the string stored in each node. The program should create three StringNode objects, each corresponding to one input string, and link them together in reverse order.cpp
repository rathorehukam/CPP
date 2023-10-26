








#include <iostream>
#include <cstring>

using namespace std;

class StringNode {
public:
    char str[101]; 
    StringNode* next; 

    // Constructor
    StringNode(const char* input) : next(nullptr) {
        strcpy(str, input);
        reverseString();
    }

    void reverseString() {
        int len = strlen(str);
        for(int i = 0; i < len / 2; ++i) {
            swap(str[i], str[len - i - 1]);
        }
    }
};

int main() {
    char input1[101], input2[101], input3[101];

    cin.getline(input1, 101);
    cin.getline(input2, 101);
    cin.getline(input3, 101);

    StringNode node1(input1);
    StringNode node2(input2);
    StringNode node3(input3);

    node1.next = &node2;
    node2.next = &node3;

    StringNode* currentNode = &node1;
    while(currentNode) {
        cout << currentNode->str << endl;
        currentNode = currentNode->next;
    }

    return 0;
}
