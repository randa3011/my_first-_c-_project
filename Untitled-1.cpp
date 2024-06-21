#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int numCourses;
    double totalCredits = 0.0;
    double totalGradePoints = 0.0;

    cout << "Enter the number of courses: ";
    cin >> numCourses;

    if (numCourses <= 0) {
        cout << "Invalid number of courses. Exiting program." << endl;
        return 1; // Exit the program if the number of courses is not valid
    }

    // Declare vectors to store credits and grades
    vector<double> credits(numCourses);
    vector<char> grades(numCourses);

    // Input for each course
    for (int i = 0; i < numCourses; ++i) {
        cout << "Enter credits for course " << i + 1 << ": ";
        cin >> credits[i];
        if (credits[i] <= 0) {
            cout << "Invalid credit value for course " << i + 1 << ". Exiting program." << endl;
            return 1; // Exit the program if the credit value is not valid
        }
        totalCredits += credits[i];

        cout << "Enter grade (A, B, C, D, F) for course " << i + 1 << ": ";
        cin >> grades[i];
        if (grades[i] != 'A' && grades[i] != 'B' && grades[i] != 'C' && grades[i] != 'D' && grades[i] != 'F') {
            cout << "Invalid grade entered for course " << i + 1 << ". Exiting program." << endl;
            return 1; // Exit the program if an invalid grade is entered
        }
    }

    // Calculate grade points based on grades
    for (int i = 0; i < numCourses; ++i) {
        switch (grades[i]) {
            case 'A':
                totalGradePoints += credits[i] * 4.0;
                break;
            case 'B':
                totalGradePoints += credits[i] * 3.0;
                break;
            case 'C':
                totalGradePoints += credits[i] * 2.0;
                break;
            case 'D':
                totalGradePoints += credits[i] * 1.0;
                break;
            case 'F':
                totalGradePoints += credits[i] * 0.0;
                break;
            default:
                // This default case should never be reached due to earlier validation
                cout << "Invalid grade entered for course " << i + 1 << endl;
        }
    }

    // Calculate CGPA
    if (totalCredits == 0) {
        cout << "Total credits cannot be zero. Exiting program." << endl;
        return 1; // Exit the program if total credits is zero
    }
    double cgpa = totalGradePoints / totalCredits;

    // Display results
    cout << fixed << setprecision(2);
    cout << "Total credits: " << totalCredits << endl;
    cout << "Total grade points: " << totalGradePoints << endl;
    cout << "CGPA: " << cgpa << endl;

    return 0;
}
