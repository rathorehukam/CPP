





#include <iostream>
#include <cstring>

char* reverseString(const char* input) {
    int len = strlen(input);
    char* reversed = new char[len + 1]; 

    for(int i = 0; i < len; i++) {
        reversed[i] = input[len - 1 - i];
    }

    reversed[len] = '\0'; 
    return reversed;
}

int main() {
    char sentence[1001];
    std::cin.getline(sentence, 1001);

    char* reversedSentence = reverseString(sentence);

    std::cout << "Reversed string: " << reversedSentence << std::endl;

    delete[] reversedSentence; 

    return 0;
}
