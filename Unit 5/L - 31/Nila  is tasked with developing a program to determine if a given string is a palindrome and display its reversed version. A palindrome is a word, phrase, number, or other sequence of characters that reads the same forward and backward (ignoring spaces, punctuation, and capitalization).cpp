









#include <iostream>
#include <cstring>

bool isPalindrome(const char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

char* reverseString(const char* str) {
    int len = strlen(str);
    char* reversedStr = new char[len + 1];
    for (int i = 0; i < len; i++) {
        reversedStr[i] = str[len - 1 - i];
    }
    reversedStr[len] = '\0';
    return reversedStr;
}

int main() {
    const int MAX_LENGTH = 100;

    char input[MAX_LENGTH];

    std::cin.getline(input, MAX_LENGTH);

    char* reversedStr = reverseString(input);
    if (isPalindrome(input)) {
        std::cout << "The input string is a palindrome." << std::endl;
    } else {
        std::cout << "The input string is not a palindrome." << std::endl;
    }

    std::cout << "Reversed string: " << reversedStr;

    delete[] reversedStr;

    return 0;
}


