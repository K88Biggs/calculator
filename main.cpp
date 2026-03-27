#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

struct HistoryEntry {
    string label;
    double value;
};

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

double readNumber(const string &prompt) {
    double value;

    while (true) {
        cout << prompt;
        if (cin >> value) {
            return value;
        }

        cout << "Invalid number. Please try again.\n";
        clearInput();
    }
}

int readMenuChoice() {
    int choice;

    while (true) {
        cout << "\n===== Advanced Calculator =====\n"
             << "1) Addition\n"
             << "2) Subtraction\n"
             << "3) Multiplication\n"
             << "4) Division\n"
             << "5) Power (x^y)\n"
             << "6) Square root\n"
             << "7) Trigonometry (sin/cos/tan in degrees)\n"
             << "8) Logarithms (ln/log10)\n"
             << "9) Factorial\n"
             << "10) Show calculation history\n"
             << "0) Exit\n"
             << "Select an option: ";

        if (cin >> choice && choice >= 0 && choice <= 10) {
            return choice;
        }

        cout << "Invalid option. Please enter a value from 0 to 10.\n";
        clearInput();
    }
}

unsigned long long factorial(unsigned int n) {
    unsigned long long result = 1;

    for (unsigned int i = 2; i <= n; ++i) {
        result *= i;
    }

    return result;
}

int main() {
    constexpr double pi = 3.14159265358979323846;
    vector<HistoryEntry> history;

    cout << fixed << setprecision(6);

    while (true) {
        int choice = readMenuChoice();

        if (choice == 0) {
            cout << "Goodbye!\n";
            break;
        }

        if (choice == 10) {
            if (history.empty()) {
                cout << "No calculations yet.\n";
            } else {
                cout << "\n--- Calculation History ---\n";
                for (size_t i = 0; i < history.size(); ++i) {
                    cout << i + 1 << ") " << history[i].label << " = " << history[i].value << '\n';
                }
            }
            continue;
        }

        double x, y, result;

        switch (choice) {
        case 1:
            x = readNumber("Enter first number: ");
            y = readNumber("Enter second number: ");
            result = x + y;
            cout << "Result: " << result << '\n';
            history.push_back({"Addition", result});
            break;
        case 2:
            x = readNumber("Enter first number: ");
            y = readNumber("Enter second number: ");
            result = x - y;
            cout << "Result: " << result << '\n';
            history.push_back({"Subtraction", result});
            break;
        case 3:
            x = readNumber("Enter first number: ");
            y = readNumber("Enter second number: ");
            result = x * y;
            cout << "Result: " << result << '\n';
            history.push_back({"Multiplication", result});
            break;
        case 4:
            x = readNumber("Enter numerator: ");
            y = readNumber("Enter denominator: ");
            if (y == 0) {
                cout << "Error: division by zero is undefined.\n";
            } else {
                result = x / y;
                cout << "Result: " << result << '\n';
                history.push_back({"Division", result});
            }
            break;
        case 5:
            x = readNumber("Enter base (x): ");
            y = readNumber("Enter exponent (y): ");
            result = pow(x, y);
            cout << "Result: " << result << '\n';
            history.push_back({"Power", result});
            break;
        case 6:
            x = readNumber("Enter number: ");
            if (x < 0) {
                cout << "Error: square root of a negative number is not real.\n";
            } else {
                result = sqrt(x);
                cout << "Result: " << result << '\n';
                history.push_back({"Square root", result});
            }
            break;
        case 7:
            x = readNumber("Enter angle in degrees: ");
            y = x * pi / 180.0;
            cout << "sin(" << x << ") = " << sin(y) << '\n';
            cout << "cos(" << x << ") = " << cos(y) << '\n';
            cout << "tan(" << x << ") = " << tan(y) << '\n';
            history.push_back({"sin(deg)", sin(y)});
            history.push_back({"cos(deg)", cos(y)});
            history.push_back({"tan(deg)", tan(y)});
            break;
        case 8:
            x = readNumber("Enter positive number: ");
            if (x <= 0) {
                cout << "Error: logarithms are defined only for numbers greater than zero.\n";
            } else {
                cout << "ln(" << x << ") = " << log(x) << '\n';
                cout << "log10(" << x << ") = " << log10(x) << '\n';
                history.push_back({"Natural log", log(x)});
                history.push_back({"Base-10 log", log10(x)});
            }
            break;
        case 9: {
            x = readNumber("Enter a non-negative integer (0 to 20): ");
            if (x < 0 || x > 20 || floor(x) != x) {
                cout << "Error: factorial input must be an integer from 0 to 20.\n";
            } else {
                unsigned int n = static_cast<unsigned int>(x);
                unsigned long long factResult = factorial(n);
                cout << n << "! = " << factResult << '\n';
                history.push_back({"Factorial", static_cast<double>(factResult)});
            }
            break;
        }
        default:
            cout << "Unexpected choice.\n";
            break;
        }
    }

    return 0;
}
