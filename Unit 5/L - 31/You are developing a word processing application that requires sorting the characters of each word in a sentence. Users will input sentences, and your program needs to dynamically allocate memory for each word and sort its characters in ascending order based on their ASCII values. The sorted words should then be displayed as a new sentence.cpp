#include <iostream>
#include <cstring>
#include <algorithm>

void sortWord(char* word) {
    int len = strlen(word);
    std::sort(word, word + len);
}

int main() {
    char sentence[10001];
    std::cin.getline(sentence, 10001);

    char* word = new char[101];
    int wordIndex = 0;

    for(int i = 0; sentence[i] != '\0'; i++) {
        if(sentence[i] != ' ') {
            word[wordIndex++] = sentence[i];
        } else {
            word[wordIndex] = '\0';
            sortWord(word);
            std::cout << word << " ";
            wordIndex = 0;
        }
    }

    word[wordIndex] = '\0';
    sortWord(word);
    std::cout << word;

    delete[] word; 
    return 0;
}
