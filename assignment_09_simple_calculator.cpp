// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
using namespace std;

void displayMenu();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b, bool& error);
int mod(int a, int b, bool& error);
double power(double base, double exp);

int main() {
    int choice = 0;

    do {
        displayMenu();

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number between 1 and 7." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl;
            continue;
        }

        if (choice == 7) {
            cout << "Goodbye!" << endl;
            break;
        }

        if (choice < 1 || choice > 7) {
            cout << "Invalid choice. Please choose a number from 1 to 7." << endl;
            cout << endl;
            continue;
        }

        // Get inputs based on operation
        if (choice == 5) {
            // Modulus operation uses integers
            int a, b;
            cout << "Enter first number : ";
            while (!(cin >> a)) {
                cout << "Invalid input. Enter an integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << "Enter second number: ";
            while (!(cin >> b)) {
                cout << "Invalid input. Enter an integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            bool error = false;
            int result = mod(a, b, error);
            if (!error) {
                cout << "Result: " << a << " % " << b << " = " << result << endl;
            }
        } 
        else {
            double a, b;
            cout << "Enter first number : ";
            while (!(cin >> a)) {
                cout << "Invalid input. Enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << "Enter second number: ";
            while (!(cin >> b)) {
                cout << "Invalid input. Enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (choice == 1) {
                cout << fixed << setprecision(2);
                cout << "Result: " << a << " + " << b << " = " << add(a, b) << endl;
            } 
            else if (choice == 2) {
                cout << fixed << setprecision(2);
                cout << "Result: " << a << " - " << b << " = " << subtract(a, b) << endl;
            } 
            else if (choice == 3) {
                cout << fixed << setprecision(2);
                cout << "Result: " << a << " * " << b << " = " << multiply(a, b) << endl;
            } 
            else if (choice == 4) {
                bool error = false;
                double result = divide(a, b, error);
                if (!error) {
                    cout << fixed << setprecision(2);
                    cout << "Result: " << a << " / " << b << " = " << result << endl;
                }
            } 
            else if (choice == 6) {
                cout << fixed << setprecision(2);
                cout << "Result: " << a << " ^ " << b << " = " << power(a, b) << endl;
            }
        }

        cout << endl; // Visual separator between calculations
    } while (choice != 7);

    return 0;
}

void displayMenu() {
    cout << "============================" << endl;
    cout << "      SIMPLE CALCULATOR     " << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
    cout << "Select an operation (1-7): ";
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b, bool& error) {
    if (b == 0) {
        cout << "Error: Cannot divide by zero." << endl;
        error = true;
        return 0.0;
    }
    error = false;
    return a / b;
}

int mod(int a, int b, bool& error) {
    if (b == 0) {
        cout << "Error: Cannot divide by zero." << endl;
        error = true;
        return 0;
    }
    error = false;
    return a % b;
}

double power(double base, double exp) {
    return pow(base, exp);
}