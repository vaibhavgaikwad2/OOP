#include <iostream>
using namespace std;

class Number {
public:
    void factorial() {
        int num;
        cout << "Enter a number: ";
        cin >> num;

        if (num < 0) {
            cout << "Factorial of a negative number is not defined." << endl;
            return;
        }

        int fact = 1;
        for (int i = 1; i <= num; i++) {
            fact *= i;
        }

        cout << "Factorial of " << num << " is " << fact << endl;
    }

    void evenOdd() {
        int num;
        cout << "Enter a number to check even or odd: ";
        cin >> num;

        if (num % 2 == 0)
            cout << num << " is even." << endl;
        else
            cout << num << " is odd." << endl;
    }
};

int main() {
    Number obj;
    obj.factorial();
    obj.evenOdd();
    return 0;
}
