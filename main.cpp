#include <iostream>
#include <fstream>   // for file handling
#include <iomanip>   // for formatting output
using namespace std;

// Structure to store student details
struct Student {
    string name;
    int rollNo;
    float marks[5];
    float total;
    float percentage;
    char grade;
};

// Function declarations
void inputStudent(Student &s);
void calculateResult(Student &s);
void displayStudent(const Student &s);
void saveToFile(const Student &s);

int main() {
    Student s;
    cout << "\n===== STUDENT REPORT CARD SYSTEM =====\n";
    inputStudent(s);
    calculateResult(s);
    displayStudent(s);
    saveToFile(s);

    cout << "\nStudent record saved to file successfully!\n";
    return 0;
}

// Function to input student details
void inputStudent(Student &s) {
    cout << "\nEnter student name: ";
    getline(cin, s.name);

    cout << "Enter roll number: ";
    cin >> s.rollNo;

    cout << "\nEnter marks of 5 subjects (out of 100):\n";
    for (int i = 0; i < 5; i++) {
        cout << "Subject " << i + 1 << ": ";
        cin >> s.marks[i];
    }
}

// Function to calculate total, percentage, grade
void calculateResult(Student &s) {
    s.total = 0;
    for (int i = 0; i < 5; i++)
        s.total += s.marks[i];

    s.percentage = s.total / 5.0;

    if (s.percentage >= 90)
        s.grade = 'A';
    else if (s.percentage >= 75)
        s.grade = 'B';
    else if (s.percentage >= 60)
        s.grade = 'C';
    else if (s.percentage >= 40)
        s.grade = 'D';
    else
        s.grade = 'F';
}

// Function to display result
void displayStudent(const Student &s) {
    cout << "\n----- STUDENT REPORT CARD -----\n";
    cout << "Name       : " << s.name << endl;
    cout << "Roll No.   : " << s.rollNo << endl;

    cout << "\nMarks in each subject:\n";
    for (int i = 0; i < 5; i++)
        cout << "Subject " << i + 1 << ": " << s.marks[i] << endl;

    cout << "\nTotal Marks : " << s.total << "/500";
    cout << "\nPercentage  : " << fixed << setprecision(2) << s.percentage << "%";
    cout << "\nGrade       : " << s.grade << endl;
}

// Function to save result to file
void saveToFile(const Student &s) {
    ofstream file("report_card.txt", ios::app); // append mode
    if (!file) {
        cout << "Error: Could not open file!\n";
        return;
    }

    file << "==============================\n";
    file << "Name: " << s.name << endl;
    file << "Roll No: " << s.rollNo << endl;
    file << "Marks: ";
    for (int i = 0; i < 5; i++)
        file << s.marks[i] << " ";
    file << "\nTotal: " << s.total << "  Percentage: " << s.percentage << "  Grade: " << s.grade << endl;
    file.close();
}