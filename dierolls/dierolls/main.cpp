//
//  main.cpp
//  dierolls
//
//  Created by Lucie Chevreuil on 9/7/24.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int rollDie() {
    return rand() % 6 + 1;
}

void addToFile(ofstream &outputFile, int roll) {
    outputFile << roll << endl;
}

void openOutputFile(ofstream &outputFile, const string &filePath) {
    outputFile.open(filePath);
    if (!outputFile) {
        cout << "Error creating file." << endl;
        exit(1);
    }
}

void closeOutputFile(ofstream &outputFile) {
    outputFile.close();
}


void openInputFile(ifstream &inputFile, const string &filePath) {
    inputFile.open(filePath);
    if (!inputFile) {
        cout << "Error opening file for reading." << endl;
        exit(1);
    }
}

void closeInputFile(ifstream &inputFile) {
    inputFile.close();
}

int readFile(ifstream &inputFile) {
    int roll;
    inputFile >> roll;
    return roll;
}

void saveReport(int one, int two, int three, int four, int five, int six) {
    ofstream reportFile("report.txt");
    if (!reportFile) {
        cout << "Error creating report file." << endl;
        exit(1);
    }

    reportFile << "one: " << one << " rolls" << endl;
    reportFile << "two: " << two << " rolls" << endl;
    reportFile << "three: " << three << " rolls" << endl;
    reportFile << "four: " << four << " rolls" << endl;
    reportFile << "five: " << five << " rolls" << endl;
    reportFile << "six: " << six << " rolls" << endl;

    reportFile.close();
    cout << "Report saved to report.txt" << endl;
}

void showReport() {
    int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;
    ifstream inputFile;
    string filePath = "rolls.txt";
    
    openInputFile(inputFile, filePath);

    int roll;
    // As long as reading the integer is successful
    while (inputFile >> roll) {
        switch (roll) {
            case 1: ++one; break;
            case 2: ++two; break;
            case 3: ++three; break;
            case 4: ++four; break;
            case 5: ++five; break;
            case 6: ++six; break;
        }
    }
    
    closeInputFile(inputFile);

    cout << "one: " << one << " rolls" << endl;
    cout << "two: " << two << " rolls" << endl;
    cout << "three: " << three << " rolls" << endl;
    cout << "four: " << four << " rolls" << endl;
    cout << "five: " << five << " rolls" << endl;
    cout << "six: " << six << " rolls" << endl;
    
    // Save the report to a file
    saveReport(one, two, three, four, five, six);
}

int main() {
    srand((unsigned)time(NULL));

    ofstream outputFile;
    string filePath = "rolls.txt";

    openOutputFile(outputFile, filePath);

    for (int i = 0; i < 100; i++) {
        int roll = rollDie();
        addToFile(outputFile, roll);
    }

    closeOutputFile(outputFile);

    cout << "100 rolls saved to rolls.txt" << endl;
    
    showReport();

    return 0;
}
