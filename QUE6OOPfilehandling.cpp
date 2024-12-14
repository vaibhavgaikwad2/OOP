#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Create and open an output file
    ofstream outFile("student_info.txt");

    // Check if file opened successfully
    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return 1;
    }

    // Write data to the file
    outFile << "Name: John Doe\n";
    outFile << "Age: 20\n";
    outFile << "Major: Computer Science\n";

    // Close the output file
    outFile.close();

    // Create and open an input file
    ifstream inFile("student_info.txt");

    // Check if file opened successfully
    if (!inFile) {
        cout << "Error opening file for reading!" << endl;
        return 1;
    }

    // Read data from the file
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    // Close the input file
    inFile.close();

    return 0;
}

