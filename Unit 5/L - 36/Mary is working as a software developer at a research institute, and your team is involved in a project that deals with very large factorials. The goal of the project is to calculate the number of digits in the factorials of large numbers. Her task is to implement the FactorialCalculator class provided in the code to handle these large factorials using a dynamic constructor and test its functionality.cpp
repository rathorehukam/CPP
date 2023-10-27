









#include <iostream>

class FactorialCalculator {
private:
    int* arr;
    int size;
    
    void multiply(int x) {
        int carry = 0;
        for(int i = 0; i < size; i++) {
            int prod = arr[i] * x + carry;
            arr[i] = prod % 10;
            carry = prod / 10;
        }
        
        while (carry) {
            int* temp = new int[size + 1];
            for(int i = 0; i < size; i++) {
                temp[i] = arr[i];
            }
            temp[size] = carry % 10;
            carry /= 10;
            delete[] arr;
            arr = temp;
            size++;
        }
    }
    
public:
    FactorialCalculator(int n) {
        arr = new int[200];
        size = 1;
        arr[0] = 1;

        for(int i = 2; i <= n; i++) {
            multiply(i);
        }
    }
    
    int getNumDigits() {
        return size;
    }
    
    ~FactorialCalculator() {
        delete[] arr;
    }
};

int main() {
    int n;
    std::cin >> n;
    if(n < 0) {
        std::cout << "Invalid input" << std::endl;
        return 0;
    }
    
    FactorialCalculator fc(n);
    std::cout << fc.getNumDigits() << std::endl;
    return 0;
}
