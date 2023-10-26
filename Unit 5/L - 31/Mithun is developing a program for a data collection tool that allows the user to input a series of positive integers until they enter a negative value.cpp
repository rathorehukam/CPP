








#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int size = 10; 
    int *numbers = new int[size];
    int count = 0;
    int num;
    
    while (cin >> num && num >= 0) {
        if(count == size) {  
            int* temp = new int[size * 2];
            for(int i = 0; i < size; i++) {
                temp[i] = numbers[i];
            }
            delete[] numbers;
            numbers = temp;
            size *= 2;
        }
        numbers[count++] = num;
    }

    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }

    double average = static_cast<double>(sum) / count;

    cout << "Numbers entered: ";
    for (int i = 0; i < count; i++) {
        cout << numbers[i];
        if (i != count - 1) {
            cout << " ";
        }
    }
    cout << endl;

    cout << "Sum of entered numbers: " << sum << endl;
    cout << fixed << setprecision(2);
    cout << "Average of entered numbers: " << average << endl;

    delete[] numbers;  

    return 0;
}
