






#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int N;

    std::cin >> N;

    std::string* names = new std::string[N];

    for (int i = 0; i < N; ++i) {
        std::cin >> names[i];
    }

    std::sort(names, names + N);

    for (int i = 0; i < N; ++i) {
        std::cout << names[i];
        if (i != N - 1) {
            std::cout << " ";
        }
    }
    delete[] names;

    return 0;
}
