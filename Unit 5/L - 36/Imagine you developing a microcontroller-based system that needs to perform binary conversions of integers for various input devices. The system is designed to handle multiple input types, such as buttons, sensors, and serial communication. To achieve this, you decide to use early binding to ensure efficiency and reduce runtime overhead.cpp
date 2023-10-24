






#include <iostream>
#include <bitset>

class BinaryConverter {
public:
    std::string intToBinary(int number) {
        return std::bitset<32>(number).to_string();
    }
};

int main() {
    int num;
    std::cin >> num;

    BinaryConverter converter;
    std::cout << "Binary representation: " << converter.intToBinary(num) << std::endl;

    return 0;
}
