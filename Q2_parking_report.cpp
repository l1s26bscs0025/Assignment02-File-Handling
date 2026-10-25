
/*
  * Name       : HASEEB AHMED
  * Reg No     : L1S26BSCS0025
  * Assignment : 02 - File Handling
  * Question   : Q2 - Parking Report
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
    ifstream inFile("parking.txt");

    if (!inFile) {
        cout << "parking.txt not found!" << endl;
        return 1;
    }

    int d, m, y;
    char slash;

    inFile >> d >> slash >> m >> slash >> y;

    inFile.ignore(100, '\n');
    inFile.ignore(100, '\n');

    ofstream outFile("receipts.txt");

    outFile << "Receipts for "
        << d << "/" << m << "/" << y << endl;

    cout << "Parking report for "
        << d << "/" << m << "/" << y << endl;

    char plate[15];
    char longestPlate[15];
    char type, colon;

    int inHour, inMin, outHour, outMin;
    int minutes, hoursCharged, fee;

    int totalVehicles = 0;
    int cars = 0;
    int bikes = 0;
    int totalCollected = 0;
    int longestMinutes = -1;

    while (totalVehicles < 30 &&
        inFile >> plate >> type
        >> inHour >> colon >> inMin
        >> outHour >> colon >> outMin) {

        int startTime = inHour * 60 + inMin;
        int endTime = outHour * 60 + outMin;

        minutes = endTime - startTime;

        hoursCharged = (minutes + 59) / 60;

        if (hoursCharged == 0) {
            hoursCharged = 1;
        }

        if (type == 'C') {
            fee = hoursCharged * 100;
            cout << plate << " Car ";
            cars++;
        }
        else {
            fee = hoursCharged * 40;
            cout << plate << " Bike ";
            bikes++;
        }

        cout << minutes / 60 << " h "
            << minutes % 60 << " min Fee: "
            << fee << endl;

        outFile << plate << " " << fee << endl;

        totalVehicles++;
        totalCollected = totalCollected + fee;

        if (minutes > longestMinutes) {
            longestMinutes = minutes;
            strcpy(longestPlate, plate);
        }
    }

    if (totalVehicles == 0) {
        cout << "No vehicles found!" << endl;
    }
    else {
        cout << "Vehicles: " << totalVehicles << endl;

        cout << "Cars: " << cars
            << " Bikes: " << bikes << endl;

        cout << "Total collected: "
            << totalCollected << endl;

        cout << "Longest stay: " << longestPlate
            << " (" << longestMinutes / 60
            << " h " << longestMinutes % 60
            << " min)" << endl;
    }

    inFile.close();
    outFile.close();

    return 0;
}
