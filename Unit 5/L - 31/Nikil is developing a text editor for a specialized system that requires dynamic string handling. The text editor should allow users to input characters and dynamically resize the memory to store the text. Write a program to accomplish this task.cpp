









#include <iostream>
#include <cstring>

int main() {
    char* dynamicString = new char[2];
    int size = 1; 
    char ch;

    std::cin.get(ch);

    while (ch != '0') {
        dynamicString[size - 1] = ch;
        dynamicString[size] = '\0';
        size++;
        char* newDynamicString = new char[size + 1];
        std::strcpy(newDynamicString, dynamicString);
        delete[] dynamicString;
        dynamicString = newDynamicString;
        std::cin.get(ch);
    }

    std::cout << "Dynamic String: " << dynamicString << std::endl;
    std::cout << "String Length: " << size - 1 << std::endl;
    delete[] dynamicString;
    return 0;
}
