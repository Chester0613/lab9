
/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: joandry A. Irizarry Roman
 * Lab: 9 - File I/O
 * Description: Saves motor current readings to a file,
 * calculates the average, and checks the current limit.
 * Due Date: [oct/21/2026]
 */

#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

// Function prototypes
double calculateAverage(double total, int count);
bool isWithinLimit(double average, double maximum);

int main() {
    int requestedSamples;
    int samplesRead = 0;
    double maximumCurrent;
    double currentReading;
    double totalCurrent = 0.0;
    double averageCurrent;

    // Ask for the number of samples
    cout << "Enter number of samples: ";
    cin >> requestedSamples;

    // Validate the number of samples
    if (requestedSamples <= 0) {
        cout << "Invalid number of samples." << endl;
        return 1;
    }

    // Ask for the maximum allowed current
    cout << "Enter maximum average current: ";
    cin >> maximumCurrent;

    // Open the output file
    ofstream outputFile("motor_current_readings.txt");

    // Check if the file opened successfully
    if (!outputFile) {
        cout << "Error: Could not create the file." << endl;
        return 1;
    }

    // Save each current reading
    outputFile << fixed << setprecision(2);

    for (int i = 1; i <= requestedSamples; i++) {
        cout << "Enter current reading " << i << ": ";
        cin >> currentReading;

        outputFile << currentReading << endl;
    }

    // Close the output file
    outputFile.close();

    // Open the input file
    ifstream inputFile("motor_current_readings.txt");

    // Check if the file opened successfully
    if (!inputFile) {
        cout << "Error: Could not open the file." << endl;
        return 1;
    }

    // Read each value from the file
    while (inputFile >> currentReading) {
        totalCurrent += currentReading;
        samplesRead++;
    }

    // Check that samples were read
    if (samplesRead == 0) {
        cout << "No readings found." << endl;
        inputFile.close();
        return 1;
    }

    // Calculate the average
    averageCurrent = calculateAverage(totalCurrent, samplesRead);

    // Display the results
    cout << fixed << setprecision(2);

    cout << "Readings processed: " << samplesRead << endl;

    cout << "Average current: " << averageCurrent << endl;

    // Check if the average is within the limit
    if (isWithinLimit(averageCurrent, maximumCurrent)) {
        cout << "Average current is within the limit." << endl;
    }
    else {
        cout << "Average current exceeds the limit." << endl;
    }

    // Close the input file
    inputFile.close();

    return 0;
}

// Function that returns the average current
double calculateAverage(double total, int count) {
    return total / count;
}

// Function that checks the maximum allowed current
bool isWithinLimit(double average, double maximum) {
    return average <= maximum;
}

/*
 * Analysis:
 *
 * 1. Why does the average function return double
 *    instead of int?
 *
 * Answer:
 * Because the average can have decimal values,
 * and double allows us to store them correctly.
 *
 * 2. What exact comparison makes the Boolean
 *    function return true?
 *
 * Answer:
 * The function returns true when the average
 * current is less than or equal to the maximum
 * allowed current (average <= maximum).
 *
 * 3. Why is samplesRead more reliable than
 *    requestedSamples for calculating the average?
 *
 * Answer:
 * Because samplesRead counts the actual readings
 * successfully read from the file, while
 * requestedSamples is only the amount requested.
 *
 * 4. Why must the output stream close before
 *    the input stream opens the same file?
 *
 * Answer:
 * To make sure all the readings are saved
 * before the program starts reading the file.
 */

