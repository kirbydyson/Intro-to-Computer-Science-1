/*
*Author: Kirby Dyson
*Assignment Title: Data Transformation
*Assignment Description: In this program the user will enter two file names.
The first file will hold the input data and the second file will store the
result of the data transformation. The first two lines of the input file will
be ignored and the next ten lines will hold one numeric value per line. The
13th line will hold a command, "aav", "mav", "avg", "dav", or "sav". The
transformed data will be written to the output file and screen. If neither
file opens, an error message will be printed.
*Due Date: 9/23/2022
*Date Created: 9/17/2022
*Date Last Modified: 9/21/2022
*/

/*
 * Data Abstraction:
         Four strings are initialized for use.
         One ifstream and one ofstream are initialized for use.
         Two doubles and one boolean are initialized for use.
 * Input:
         The program inputs two files, fileName1 and fileName2.
         The program opens two files, inputFile and outputFile.
         If the inputFile and outputFile do not open, the bool
         badFile is assigned to true.
         Ten numbers are read from the input file.
         The input file is closed.
 * Process:
         If the command is "aav" all numbers are added.
         If the command is "mav" all numbers are multiplied.
         If the command is "avg" the average of the numbers are calculated.
         If the command is "dav" all numbers are divided.
         If the command is "sav" all numbers are subtracted.
 * Output:
         If the files do not open, an error message is printed.
         If the files do open, the output file is printed to the screen.
         The output file is closed.
 * Assumptions:
         It is assumed that there will be two file inputs.
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    //Data Abstraction
    string fileName1;
    string fileName2;
    string command;
    string blank;
    ifstream inputFile;
    ofstream outputFile;
    double n1, n2, n3, n4, n5, n6, n7, n8, n9, n10;
    double dataResult;
    bool badFile = false;

    //Input
    cin >> fileName1;
    cin >> fileName2;
    inputFile.open(fileName1);
    outputFile.open(fileName2);
    if ((!inputFile.is_open()) || (!outputFile.is_open())) {
        badFile = true;
    }
    getline(inputFile , blank);
    getline(inputFile , blank);
    inputFile >> n1;
    inputFile >> n2;
    inputFile >> n3;
    inputFile >> n4;
    inputFile >> n5;
    inputFile >> n6;
    inputFile >> n7;
    inputFile >> n8;
    inputFile >> n9;
    inputFile >> n10;
    inputFile >> command;
    inputFile.close();

    //Process
    if (command == "aav") {
        dataResult = n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8 + n9 + n10;
    }
    if (command == "mav") {
        dataResult = n1 * n2 * n3 * n4 * n5 * n6 * n7 * n8 * n9 * n10;
    }
    if (command == "avg") {
        dataResult = (n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8 + n9 + n10) / 10;
    }
    if (command == "dav") {
        dataResult = n1 / n2 / n3 / n4 / n5 / n6 / n7 / n8 / n9 / n10;
    }
    if (command == "sav") {
        dataResult = n1 - n2 - n3 - n4 - n5 - n6 - n7 - n8 - n9 - n10;
    }

    //Output
    if (badFile) {
        cout << "ERROR: File failed to open." << endl;
    }
    else {
        outputFile << dataResult << endl;
        cout << dataResult << endl;
    }
    outputFile.close();

    return 0;
}
