
/*
  * Name       : HASEEB AHMED
  * Reg No     : L1S26BSCS0025
  * Assignment : 02 - File Handling
  * Question   : Q3 - Scholarship
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
    char path[100], name[30], topName[30];
    int n, count = 0, eligible = 0;
    double cgpa, total = 0, highest = -1;

    cout << "Enter the file name: ";
    cin.getline(path, 100);

    ifstream inFile(path);

    if (!inFile.is_open()) {
        cout << "Could not open " << path << "!" << endl;
        return 1;
    }

    inFile >> n;

    if (n > 30) {
        cout << "Too many students!" << endl;
        inFile.close();
        return 1;
    }

    inFile.ignore(100, '\n');

    ofstream outFile("scholarship.txt");

    while (count < n) {
        inFile.getline(name, 30, ',');

        if (!inFile) {
            break;
        }

        if (!(inFile >> cgpa)) {
            break;
        }

        inFile.ignore(100, '\n');

        cout << "[" << name << "] CGPA: "
            << cgpa << endl;

        total = total + cgpa;
        count++;

        if (cgpa >= 3.50) {
            outFile << name << "," << cgpa << endl;
            eligible++;
        }

        if (cgpa > highest) {
            highest = cgpa;
            strcpy(topName, name);
        }
    }

    if (count < n) {
        cout << "Warning: only " << count
            << " of " << n << " records found."
            << endl;
    }

    if (count == 0) {
        cout << "No students found!" << endl;
    }
    else {
        cout << "Students: " << count << endl;
        cout << "Average CGPA: " << total / count << endl;
        cout << "Eligible for scholarship: "
            << eligible << endl;
        cout << "Top student: " << topName
            << " (" << highest << ")" << endl;
    }

    inFile.close();
    outFile.close();

    return 0;
}
