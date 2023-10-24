





#include <iostream>
#include <string>

class BaseConverter {
public:
    virtual std::string convert(int decimal) = 0; 
};

class DecimalToOctalConverter : public BaseConverter {
public:
    std::string convert(int decimal) override {
        if (decimal == 0) {
            return "0";
        }

        std::string octal = "";
        int quotient = decimal;
        while (quotient != 0) {
            int remainder = quotient % 8;
            octal = std::to_string(remainder) + octal;
            quotient /= 8;
        }

        return octal;
    }
};

int main() {
    int decimalNumber;
    std::cin >> decimalNumber;
    BaseConverter* converter = new DecimalToOctalConverter();
    std::cout << converter->convert(decimalNumber) << std::endl;
    delete converter;

    return 0;
}
