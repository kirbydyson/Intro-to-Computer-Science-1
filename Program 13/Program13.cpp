/*
*Author: Kirby Dyson
*Assignment Title: GPS
*Assignment Description: This program will process a stream of GPS data. Each
line of data starts with a command, followed by the data for that command.
There will be one command per line. The user will be asked to enter the GPS
data file name and print an error message if the file does not open.
The first two lines of the data file will be skipped and each command will be
processed. The final location, total distance traveled, final distance to
start point, and average distance from the start point will be reported.
*Due Date: 10/07/2022
*Date Created: 10/03/2022
*Date Last Modified: 10/04/2022
*/

/*
 * Data Abstraction:
         Three strings are initialized for use.
         One ifstream and one integer is initialized for use.
         Twelve doubles are initialized for use.
         Two bools are initialized for use and assigned to false.
 * Input:
         The program inputs and opens a file. The file name is printed to the
         screen. If the file does not open, an error message is printed.
         The first two lines of the file are skipped.
 *Process:
         The commands in the file are processed and if the command is start or
         stop, their bool is assigned to true. The total distance, final
         distance to start point, and average distance from the start point
         are calculated (rounded to one decimal place).
 * Output:
         The final location, total distance traveled, final distance to start
         point, and average distance from the start point are printed to the
         screen.
 * Assumptions:
         It is assumed that all coordinates are in a two dimension cartesian
         coordinate plane.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    //Data Abstraction
    string fileName;
    string command;
    string blank;
    ifstream inputFile;
    double totalDistance, stDistance, avgDistance, sum;
    double startX, startY, stopX, stopY;
    double currX, currY, prevX, prevY;
    int numCount;
    bool start = false;
    bool stop = false;


    //Input
    do {
        cout <<"Please Enter The Name Of The Data File: ";
        cin >> fileName;
        cout << fileName << endl;

        inputFile.open(fileName);

        if (!inputFile) {
            cout << "Error: File failed to open." << endl;
        }
    }
    while (!inputFile);

    getline(inputFile, blank);
    getline(inputFile, blank);


    //Process
    while (!start) {
        inputFile >> command >> currX >> currY;
        if (command == "START") {
            start = true;
        }
    }
    startX = currX;
    startY = currY;

    numCount = 0;
    while (!stop) {
        prevX = currX;
        prevY = currY;
        inputFile >> command >> currX >> currY;
        totalDistance += sqrt((pow(currX - prevX , 2)) +
        pow(currY - prevY , 2));
        stDistance = sqrt((pow(startX - currX , 2)) +
        pow(startY - currY , 2));
        sum += sqrt((pow(currX - startX , 2)) +
        pow(currY - startY , 2));
        numCount++;
        if (command == "STOP") {
            stop = true;
        }
    }
    stopX = currX;
    stopY = currY;
    avgDistance = sum / numCount;


    //Output
    cout << endl;
    cout << fixed << setprecision(1);
    cout << "Final Location: (" << stopX << ", " << stopY << ")" << endl;
    cout << "Total distance traveled " << totalDistance << endl;
    cout << "Distance to starting point " << stDistance << endl;
    cout << "Average distance to start point = " << avgDistance << endl;
    inputFile.close();

    return 0;
}
