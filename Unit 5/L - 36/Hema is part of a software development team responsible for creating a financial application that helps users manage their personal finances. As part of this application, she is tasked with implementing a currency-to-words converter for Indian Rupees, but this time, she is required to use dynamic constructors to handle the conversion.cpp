






#include <iostream>
#include <string>

class NumberToWordsConverter {
    int amount;

public:
    // Dynamic constructor
    NumberToWordsConverter(int a) : amount(a) {}

    std::string convertToWords(int n) {
        std::string oneToNineteen[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        std::string tensMultiple[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        std::string ans = "";

        if (n < 20) {
            return oneToNineteen[n - 1];
        } else if (n < 100) {
            return tensMultiple[n / 10] + (n % 10 ? " " + oneToNineteen[n % 10 - 1] : "");
        } else {
            return "Invalid input";
        }
    }

    std::string convert() {
        if (amount <= 0 || amount > 99999) {
            return "Invalid input";
        }

        std::string output = "";
        if (amount / 1000) {
            output += convertToWords(amount / 1000) + " Thousand ";
            amount %= 1000;
        }
        if (amount / 100) {
            output += convertToWords(amount / 100) + " Hundred ";
            amount %= 100;
        }
        if (amount) {
            if (!output.empty()) {
               // output += "and ";
            }
            output += convertToWords(amount);
        }
        return output;
    }
};

int main() {
    int amt;
    std::cin >> amt;

    NumberToWordsConverter* converter = new NumberToWordsConverter(amt);
    std::cout << converter->convert() << std::endl;
    delete converter;

    return 0;
}
