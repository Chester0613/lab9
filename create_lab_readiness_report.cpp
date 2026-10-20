
/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: Joandry A. Irizarry Roman
 * Lab: 9 - File I/O
 * Description: Calculates available workstations and
 * creates a laboratory readiness report.
 * Due Date: [oct/21/2026]
 */

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// Function prototypes
int calculateAvailableWorkstations(int totalWorkstations,
                                   int unavailableWorkstations);

bool canOpenWorkshop(int availableWorkstations,
                     int minimumRequired);

int main() {
    string labName;
    int totalWorkstations;
    int unavailableWorkstations;
    int minimumRequired;
    int availableWorkstations;
    bool workshopCanOpen;

    // Get laboratory information
    cout << "Enter laboratory name: ";
    getline(cin, labName);

    cout << "Enter total workstations: ";
    cin >> totalWorkstations;

    cout << "Enter unavailable workstations: ";
    cin >> unavailableWorkstations;

    cout << "Enter minimum workstations required: ";
    cin >> minimumRequired;

    // Calculate available workstations
    availableWorkstations =
        calculateAvailableWorkstations(totalWorkstations,
                                       unavailableWorkstations);

    // Check if the workshop can open
    workshopCanOpen =
        canOpenWorkshop(availableWorkstations,
                        minimumRequired);

    // Display results
    cout << "Available workstations: "
         << availableWorkstations << endl;

    cout << boolalpha;
    cout << "Workshop can open: "
         << workshopCanOpen << endl;

    // Create the report file
    ofstream outputFile("lab_readiness_report.txt");

    // Check if file opened successfully
    if (!outputFile) {
        cout << "Error: Could not create the report file."
             << endl;
        return 1;
    }

    // Write information to the file
    outputFile << "Lab Readiness Report" << endl;
    outputFile << "Laboratory: " << labName << endl;
    outputFile << "Total workstations: "
               << totalWorkstations << endl;
    outputFile << "Unavailable workstations: "
               << unavailableWorkstations << endl;
    outputFile << "Minimum required: "
               << minimumRequired << endl;
    outputFile << "Available workstations: "
               << availableWorkstations << endl;

    // Write workshop status
    if (workshopCanOpen) {
        outputFile << "Workshop can open." << endl;
    }
    else {
        outputFile << "Workshop cannot open." << endl;
    }

    // Close the file
    outputFile.close();

    cout << "Report created successfully." << endl;

    return 0;
}

// Function to calculate available workstations
int calculateAvailableWorkstations(
    int totalWorkstations,
    int unavailableWorkstations) {

    return totalWorkstations - unavailableWorkstations;
}

// Function to check workshop readiness
bool canOpenWorkshop(int availableWorkstations,
                     int minimumRequired) {

    return availableWorkstations >= minimumRequired;
}

/*
 * Analysis:
 *
 * 1. What value does the availability function
 *    return for your test case?
 *
 * Answer:
 * The function returns 9 because there are 12
 * total workstations and 3 are unavailable.
 *
 * 2. What condition makes the Boolean function
 *    return true?
 *
 * Answer:
 * The function returns true when the available
 * workstations are greater than or equal to
 * the minimum required.
 *
 * 3. Why must the output stream be closed
 *    after writing the report?
 *
 * Answer:
 * To make sure all the information is saved
 * correctly and the file is properly closed.
 */
