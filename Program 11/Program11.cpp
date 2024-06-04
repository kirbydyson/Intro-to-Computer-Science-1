/*
*Author: Kirby Dyson
*Assignment Title: Mix Max Sum Count Average
*Assignment Description: In this program the user will ask for the name of a
data file, open the data file, and read an unknown number of integers from the
file. The min, max, sum, count, and average of the data will then be printed,
rounded to two decimal places.
*Due Date: 9/30/2022
*Date Created: 9/27/2022
*Date Last Modified: 9/29/2022
*/

/*
 * Data Abstraction:
         One string and one ifstream are initialized for use.
         Five integers are initialized for use.
         One double is initialized for use.
 * Input:
         The program will ask the user for the name of a data file and
         echo print the file name. If the file fails to open, an error
         message will print and prompt the user for another name.
 * Process:
         The minimum, maximum, sum, number count, and average are calculated.
         When the end of the file is reached, the program will stop reading.
         The input file is closed.
 * Output:
         The minimum, maximum, sum, number count, and average are printed
         to the screen, with the average rounded to two decimal places.
 * Assumptions:
         It is assumed that there will be valid inputs.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
    //Data Abstraction
    string fileName;
    ifstream inputFile;
    int numMin, numMax, numSum, numCount;
    int unknownNums;
    double numAvg;

    //Input
    do {
        cout << "Enter Data File Name: ";
        cin >> fileName;
        cout << fileName << endl;

        inputFile.open(fileName);

        if (!inputFile) {
            cout << "ERROR: File Not Open." << endl;
        }
    }
    while (!inputFile);

    //Process
    numCount = 0;

    while (inputFile >> unknownNums) {
        numSum += unknownNums;
        numCount++;
        if (numCount == 1) {
            numMax = unknownNums;
            numMin = unknownNums;
        }
        if (unknownNums < numMin) {
            swap(unknownNums , numMin);
        }
        if (unknownNums > numMax) {
            swap(unknownNums , numMax);
        }
    }
    numAvg = ((static_cast<double>(numSum)) / numCount);

    inputFile.close();

    //Output
    cout << endl;
    cout << "Min = " << numMin << endl;
    cout << "Max = " << numMax << endl;
    cout << "Sum = " << numSum << endl;
    cout << "Count = " << numCount << endl;
    cout << fixed << setprecision(2);
    cout << "Average = " << numAvg << endl;

    return 0;
}
