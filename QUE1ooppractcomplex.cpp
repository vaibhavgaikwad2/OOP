#include <iostream>
using namespace std;

class Complex {
    double real, imag;

public:
    // Default and Parameterized Constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload + operator to add two complex numbers
    Complex operator+(const Complex &c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    // Overload * operator to multiply two complex numbers
    Complex operator*(const Complex &c) const {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    // Overload >> operator to input a complex number
    friend istream &operator>>(istream &in, Complex &c) {
        cout << "Enter real and imaginary parts: ";
        in >> c.real >> c.imag;
        return in;
    }

    // Overload << operator to output a complex number
    friend ostream &operator<<(ostream &out, const Complex &c) {
        out << c.real << (c.imag >= 0 ? "+" : "") << c.imag << "i";
        return out;
    }
};

int main() {
    Complex c1, c2;
    cout << "Input first complex number:" << endl;
    cin >> c1;
    cout << "Input second complex number:" << endl;
    cin >> c2;

    Complex sum = c1 + c2;
    Complex product = c1 * c2;

    cout << "Sum: " << sum << endl;
    cout << "Product: " << product << endl;

    return 0;
}
