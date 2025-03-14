#include <iostream> // includes the iostream library for input/output operations
using namespace std; //line allows you to use standard library names without the std:: prefix.

int main() { //This is the entry point of the program.
    double x; //Variable Declarations: Two double variables, x and y, are declared to store the numbers input by the user.
    double y;

    cout << "Enter a number: "; // The program prompts the user to enter two numbers and stores them in x and y.
    cin >> x;
    cout << "Enter another number: ";
    cin >> y;

    double mySum = x + y;            //The program calculates the sum, multiplication, subtraction, division, and modulus of x and y.
    double myMultiplication = x * y;
    double mySubtraction = x - y;
    double myDivision = (y != 0) ? x / y : 0; // Avoid division by zero
    int myMod = (y != 0) ? static_cast<int>(x) % static_cast<int>(y) : 0; // Avoid division by zero

    cout << "Sum: " << mySum << endl; //The program prints the results of the calculations.
    cout << "Multiplication: " << myMultiplication << endl;
    cout << "Subtraction: " << mySubtraction << endl;
    if (y != 0) {
        cout << "Division: " << myDivision << endl;
        cout << "Modulus: " << myMod << endl;
    } else {
        cout << "Division and Modulus: Undefined (division by zero)" << endl; //If y is zero, it prints a message indicating that division and modulus are undefined.
    }

    return 0; //The program returns 0, indicating successful execution.
}
