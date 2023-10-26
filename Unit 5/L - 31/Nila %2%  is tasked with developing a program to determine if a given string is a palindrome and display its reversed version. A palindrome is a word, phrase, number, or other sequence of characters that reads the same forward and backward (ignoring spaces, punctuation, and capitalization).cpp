




#include <iostream>
#include <cstring>
#include <cctype>
bool isPalindrome(const char* str) {
    int left = 0, right = strlen(str) - 1;
    while(left < right) {
        while(left < right && !isalnum(str[left])) {
            left++;
        }
        while(left < right && !isalnum(str[right])) {
            right--;
        }
        if(tolower(str[left]) != tolower(str[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

char* reverseString(const char* str) {
    int length = strlen(str);
    char* reversed = new char[length + 1];
    for(int i = 0; i < length; i++) {
        reversed[i] = str[length - 1 - i];
    }
    reversed[length] = '\0';
    return reversed;
}

int main() {
    char input[101];  
    std::cin.getline(input, 101);

    if(isPalindrome(input)) {
        std::cout << "The input string is a palindrome." << std::endl;
    } else {
        std::cout << "The input string is not a palindrome." << std::endl;
    }

    char* reversed = reverseString(input);
    std::cout << "Reversed string: " << reversed << std::endl;

    delete[] reversed;  
    return 0;
}
