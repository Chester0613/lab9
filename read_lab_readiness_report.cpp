/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: Joandry A. Irizarry Roman
 * Lab: 9 - File I/O
 * Description: Reads and displays the laboratory
 * readiness report from a text file.
 * Due Date: [oct/21/2026]
 */

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {

    // Open the existing report file
    ifstream inputFile("lab_readiness_report.txt");

    string line;

    // Check if the file opened successfully
    if (!inputFile) {
        cout << "Error: Could not open the report file."
             << endl;
        return 1;
    }

    // Display the report heading
    cout << "=== Laboratory Readiness Report ==="
         << endl;

    // Read and display each line
    while (getline(inputFile, line)) {
        cout << line << endl;
    }

    // Close the file
    inputFile.close();

    return 0;
}

/*
 * Analysis:
 *
 * 1. Why does this program use ifstream
 *    instead of ofstream?
 *
 * Answer:
 * Because ifstream is used to read information
 * from an existing file, while ofstream is used
 * to write information to a file.
 *
 * 2. What causes the while loop to stop?
 *
 * Answer:
 * The while loop stops when getline cannot
 * read another line, normally because it
 * reaches the end of the file.
 *
 * 3. Why must the program test the input
 *    stream before reading?
 *
 * Answer:
 * To make sure the file opened successfully
 * and avoid trying to read a file that
 * could not be opened.
 */
