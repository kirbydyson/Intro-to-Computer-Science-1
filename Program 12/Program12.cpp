/*
*Author: Kirby Dyson
*Assignment Title: Caesar Cipher
*Assignment Description: In this program the user will ask for the name of a
file and for the user to enter 'encrypt' or 'decrypt'. If the user enters
anything else, an error message will be printed and the program will exit.
If 'encrypt' is entered, the program will open the file and encrypt it by
shifting each character (including white space) 3 values to the right. If
'decrypt' is entered, the program will open the file and decrypt it by
shifting each character (including white space) 3 values to the left. If the
file fails to open, the program will exit and print an error message. The
decrypted or encrypted message will be displayed to the screen and written to
an output file named "message". The frequency of the vowels in input message
will also be reported.
*Due Date: 10/5/2022
*Date Created: 9/30/2022
*Date Last Modified: 10/3/2022
*/

/*
 * Data Abstraction:
         Two bools are initialized for use.
         Three strings are initialized for use.
         One ifstream and one ofstream are initialized for use.
         Seven integers are initialized for use.
         One char is initialized for use.

 * Input:
         The program inputs and opens a file. The file name is printed to the
         screen. If the file fails to open, badFile is assigned to true.
         The program inputs and prints a command. If the command is not
         'encrypt' or 'decrypt', badCommand is assigned to true.
         An output file is also opened.
 *Process:
         The characters are shifted depending on the command.
         The frequency of the vowels is determined.
         The input file is closed.
 * Output:
         If the input file did not open, an error message is printed.
         If the command was not 'encrypt' or 'decrypt' an error message is
         printed.
         If there is no error, the message is written to an output file named
         message. The message is printed to the screen.
         The letter and frequency of the vowels are printed to the
         screen.
         The output file is closed.
 * Assumptions:
         It is assumed that there will be valid inputs.
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    //Data Abstraction
    bool badCommand = false;
    bool badFile = false;
    string message;
    string fileName;
    string command;
    ifstream inputFile;
    ofstream outputFile;
    int aCount = 0;
    int eCount = 0;
    int iCount = 0;
    int oCount = 0;
    int uCount = 0;
    int yCount = 0;
    int shift = 3;
    char c;


    //Input
    cout << "Enter File Name: ";
    cin >> fileName;
    cout << fileName << endl;

    cout << "Enter encrypt or decrypt: ";
    cin >> command;
    cout << command << endl;;

    inputFile.open(fileName);
    outputFile.open("message");
    if (!inputFile.is_open()) {
        badFile = true;
    }

    if (command != "encrypt" && command != "decrypt") {
        badCommand = true;
    }
    else if (command == "decrypt") {
        shift = -3;
    }

    //Process
    while (inputFile.get(c)) {
        if (c == 'A' || c == 'a') {
            aCount++;
        }
        else if (c == 'E' || c == 'e') {
            eCount++;
        }
        else if (c == 'I' || c == 'i') {
            iCount++;
        }
        else if (c == 'O' || c == 'o') {
            oCount++;
        }
        else if (c == 'U' || c == 'u') {
            uCount++;
        }
        else if (c == 'Y' || c == 'y') {
            yCount++;
        }

    c += shift;
    message += c;
    }

    inputFile.close();

    //Output
    if (badCommand) {
       cout << "Error: Bad Command." << endl;
    }
    if (badFile) {
        cout << "Error: File did NOT open." << endl;
    }
    else {
        outputFile << message << endl;
        cout << endl;
        cout << message << endl;
        cout << endl;
        cout << "Letter Frequency" << endl;
        cout << "   A   " << aCount << endl;
        cout << "   E   " << eCount << endl;
        cout << "   I   " << iCount << endl;
        cout << "   O   " << oCount << endl;
        cout << "   U   " << uCount << endl;
        cout << "   Y   " << yCount << endl;
    }
    outputFile.close();

    return 0;
}
