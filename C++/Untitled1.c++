#include <iostream>
using namespace std;

int main() {
    int number;

    // Ask the user to input a number
    cout << "Enter an integer: ";
    cin >> number;

    // Determine if the number is even or odd
    if (number % 2 == 0) {
        cout << number << " is even." << endl;
    } else {
        cout << number << " is odd." << endl;
    }

    return 0;
}

