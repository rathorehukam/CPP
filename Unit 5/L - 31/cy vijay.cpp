




#include <iostream>
class Polynomial {
private:
int degree; 
int* coefficients; 
public:
Polynomial(int degree, int* coeffs) : degree(degree) {
coefficients = new int[degree + 1];
for (int i = 0; i <= degree; ++i) {
coefficients[i] = coeffs[i];
}
}

~Polynomial() {
delete[] coefficients;

}




// Function to evaluate the polynomial for a given value of x
int evaluate(int x) const {

int result = 0;

int x_power = 1;

for (int i = 0; i <= degree; ++i) {

result += coefficients[i] * x_power;

x_power *= x;

}

return result;

}




Polynomial add(const Polynomial& other) const {

int max_degree = std::max(degree, other.degree);

int* result_coeffs = new int[max_degree + 1];




for (int i = 0; i <= max_degree; ++i) {

int coeff1 = (i <= degree) ? coefficients[i] : 0;

int coeff2 = (i <= other.degree) ? other.coefficients[i] : 0;

result_coeffs[i] = coeff1 + coeff2;

}




Polynomial result(max_degree, result_coeffs);

delete[] result_coeffs;




return result;

}




Polynomial subtract(const Polynomial& other) const {

int max_degree = std::max(degree, other.degree);

int* result_coeffs = new int[max_degree + 1];




for (int i = 0; i <= max_degree; ++i) {

int coeff1 = (i <= degree) ? coefficients[i] : 0;

int coeff2 = (i <= other.degree) ? other.coefficients[i] : 0;

result_coeffs[i] = coeff1 - coeff2;

}




Polynomial result(max_degree, result_coeffs);

delete[] result_coeffs;




return result;

}




// Function to print the polynomial

void print() const {

for (int i = degree; i >= 0; --i) {

if (coefficients[i] != 0) {

if (i < degree) {

std::cout << ((coefficients[i] > 0) ? " + " : " - ");

}

std::cout << std::abs(coefficients[i]);

if (i > 0) {

std::cout << "x";

if (i > 1) {

std::cout << "^" << i;

}

}

}

}

std::cout << std::endl;

}

};




int main() {

int degree1, degree2;




std::cin >> degree1;

int* coeffs1 = new int[degree1 + 1];

for (int i = degree1; i >= 0; --i) {

std::cin >> coeffs1[i];

}

Polynomial poly1(degree1, coeffs1);




std::cin >> degree2;

int* coeffs2 = new int[degree2 + 1];

for (int i = degree2; i >= 0; --i) {

std::cin >> coeffs2[i];

}

Polynomial poly2(degree2, coeffs2);




poly1.print();




poly2.print();




int x;

std::cin >> x;

std::cout << poly1.evaluate(x) << std::endl;

std::cout << poly2.evaluate(x) << std::endl;




Polynomial sum = poly1.add(poly2);

sum.print();




Polynomial diff = poly1.subtract(poly2);

diff.print();




// Clean up dynamically allocated memory

delete[] coeffs1;

delete[] coeffs2;




return 0;

}
