// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};

void displayMenu();
void addStudent(vector<Student>& students);
void displayAllStudents(const vector<Student>& students);
void calculateAverageScore(const vector<Student>& students);
double computeAverage(const vector<double>& scores);


int main() {
    vector<Student> students;
    int choice = 0;

    do {
        displayMenu();
        
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a choice between 1 and 4." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                calculateAverageScore(students);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 4." << endl;
        }

        cout << endl;
    } while (choice != 4);

    return 0;
}


// HELPER FUNCTION: Compute Average of Scores
// -----------------------------------------------------------------------------
double computeAverage(const vector<double>& scores) {
    if (scores.empty()) return 0.0;
    
    double sum = 0.0;
    for (double score : scores) {
        sum += score;
    }
    return sum / scores.size();
}

void displayMenu() {
    cout << "================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU   " << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}

void addStudent(vector<Student>& students) {
    Student newStudent;

    cout << "Student name: ";
    getline(cin, newStudent.name);

    cout << "Student ID: ";
    while (!(cin >> newStudent.id)) {
        cout << "Invalid ID. Please enter a valid integer ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int count = 0;
    cout << "How many scores? ";
    while (!(cin >> count) || count < 0) {
        cout << "Please enter a valid non-negative number of scores: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int i = 0; i < count; i++) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        while (!(cin >> score)) {
            cout << "Invalid score. Re-enter score " << (i + 1) << ": ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        newStudent.scores.push_back(score);
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    students.push_back(newStudent);
    cout << "Student \"" << newStudent.name << "\" added successfully." << endl;
}

void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records available." << endl;
        return;
    }

    cout << "\n------------------------------------------------------------" << endl;
    cout << left << setw(20) << "Name" 
         << setw(12) << "ID" 
         << setw(20) << "Scores" 
         << setw(10) << "Average" << endl;
    cout << "------------------------------------------------------------" << endl;

    cout << fixed << setprecision(2);

    for (const auto& student : students) {
        // Build scores string representation
        string scoresStr = "";
        for (size_t i = 0; i < student.scores.size(); i++) {
            scoresStr += to_string(static_cast<int>(student.scores[i]));
            if (i + 1 < student.scores.size()) {
                scoresStr += ", ";
            }
        }
        if (scoresStr.empty()) scoresStr = "None";

        double avg = computeAverage(student.scores);

        cout << left << setw(20) << student.name 
             << setw(12) << student.id 
             << setw(20) << scoresStr 
             << setw(10) << avg << endl;
    }
    cout << "------------------------------------------------------------" << endl;
}

void calculateAverageScore(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records available." << endl;
        return;
    }

    int targetID;
    cout << "Enter student ID: ";
    if (!(cin >> targetID)) {
        cout << "Invalid ID format entered." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (const auto& student : students) {
        if (student.id == targetID) {
            double avg = computeAverage(student.scores);
            cout << fixed << setprecision(2);
            cout << student.name << "'s average score: " << avg << endl;
            return;
        }
    }

    cout << "Error: Student with ID " << targetID << " not found." << endl;
}