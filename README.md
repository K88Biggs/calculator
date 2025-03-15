# Description
This program is a simple calculator written in C++. It prompts the user to enter two numbers and then performs basic arithmetic operations (addition, multiplication, subtraction, division, and modulus) on those numbers. The results are displayed to the user.

# Features
Prompts the user to enter two numbers.
Calculates and displays the sum, multiplication, subtraction, division, and modulus of the two numbers.
Handles division by zero by displaying an appropriate message.
# Code Explanation

#include <iostream> // Includes the iostream library for input/output operations
using namespace std; // Allows the use of standard library names without the std:: prefix

int main() {
    double x; // Variable declarations for storing user input
    double y;

    cout << "Enter a number: "; // Prompts the user to enter the first number
    cin >> x;
    cout << "Enter another number: "; // Prompts the user to enter the second number
    cin >> y;

    double mySum = x + y; // Calculates the sum of x and y
    double myMultiplication = x * y; // Calculates the multiplication of x and y
    double mySubtraction = x - y; // Calculates the subtraction of y from x
    double myDivision = (y != 0) ? x / y : 0; // Calculates the division of x by y, avoiding division by zero
    int myMod = (y != 0) ? static_cast<int>(x) % static_cast<int>(y) : 0; // Calculates the modulus of x and y, avoiding division by zero

    // Displays the results of the calculations
    cout << "Sum: " << mySum << endl;
    cout << "Multiplication: " << myMultiplication << endl;
    cout << "Subtraction: " << mySubtraction << endl;
    if (y != 0) {
        cout << "Division: " << myDivision << endl;
        cout << "Modulus: " << myMod << endl;
    } else {
        cout << "Division and Modulus: Undefined (division by zero)" << endl;
    }

    return 0; // Indicates successful execution
}
# How to Run
Make sure you have a C++ compiler installed on your system.
Save the code to a file named calculator.cpp.
Open a terminal or command prompt and navigate to the directory where calculator.cpp is saved.
Compile the code using the command: g++ calculator.cpp -o calculator
Run the compiled program using the command: ./calculator (on Unix-based systems) or calculator.exe (on Windows).
