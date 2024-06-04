/*
*Author: Kirby Dyson
*Assignment Title: Letter Grade
*Assignment Description: In this program the user will enter 5 test scores,
sort the test scores, and then calculate their average, letter grade, min,
max, and median. The average, letter grade min, max, and median will then
print to the screen. If any scores are not between 0-100, an error message
will print to the screen.
*Due Date: 9/16/2022
*Date Created: 9/11/2022
*Date Last Modified: 9/14/2022
*/

/*
 * Data Abstraction:
         Six doubles are initialized for use.
         One boolean and one character are initialized for use.
 * Input:
         The program inputs five numbers known as n1, n2, n3, n4,
         and n5.
         The five numbers are then printed to the screen.
 * Process:
         The five numbers are checked to make sure they are between 0-100.
         The five numbers are sorted from least to greatest.
         The average, letter grade, min, max, and median are calculated.
 * Output:
         The average, letter grade, mix, max, and median are printed to
         the screen if the test scores are between 0-100, if they are not,
         an error message will be printed instead.
 * Assumptions:
         It is assumed that there will be numerical inputs.
 */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    //Data Abstraction
    double n1;
    double n2;
    double n3;
    double n4;
    double n5;
    double numAverage;
    bool goodData;
    char numGrade;

    //Input
    cout << "Please Enter Five Test Scores." << endl;
    cout << fixed << setprecision(2);
    cin >> n1;
    cout << n1 << " ";
    cin >> n2;
    cout << n2 << " ";
    cin >> n3;
    cout << n3 << " ";
    cin >> n4;
    cout << n4 << " ";
    cin >> n5;
    cout << n5 << " ";
    cout << endl;

    //Process
    if ((n1 < 0) || (n1 > 100)) {
        goodData = false;
    }
    else if ((n2 < 0) || (n2 > 100)) {
        goodData = false;
    }
    else if ((n3 < 0) || (n3 > 100)) {
        goodData = false;
    }
    else if ((n4 < 0) || (n4 > 100)) {
        goodData = false;
    }
    else if ((n5 < 0) || (n5 > 100)) {
        goodData = false;
    }
    else {
        goodData = true;
    }
    if (n1 > n2) {
        swap (n1 , n2);
    }
    if (n1 > n3) {
        swap (n1 , n3);
    }
    if (n1 > n4) {
        swap (n1 , n4);
    }
    if (n1 > n5) {
        swap (n1 , n5);
    }
    if (n2 > n3) {
        swap (n2 , n3);
    }
    if (n2 > n4) {
        swap (n2 , n4);
    }
    if (n2 > n5) {
        swap (n2, n5);
    }
    if (n3 > n4) {
        swap (n3 , n4);
    }
    if (n3 > n5) {
        swap (n3 , n5);
    }
    if (n4 > n5) {
        swap (n4 , n5);
    }
    numAverage = ((n1 + n2 + n3 + n4 + n5) / 5);
    if (numAverage >= 89.5) {
        numGrade = 'A';
    }
    else if (numAverage >= 79.5) {
        numGrade = 'B';
    }
    else if (numAverage >= 69.5) {
        numGrade = 'C';
    }
    else if (numAverage >= 59.5) {
        numGrade = 'D';
    }
    else if (numAverage <= 59.49) {
        numGrade = 'F';
    }

    //Output
    if (goodData == true) {
        cout << endl;
        cout << "Average = " << numAverage << endl;
        cout << "Grade = " << numGrade << endl;
        cout << "Min = " << n1 << endl;
        cout << "Max = " << n5 << endl;
        cout << "Median = " << n3 << endl;
    }
    else if (goodData == false) {
        cout << "ERROR: BAD DATA";
    }
    return 0;
}
