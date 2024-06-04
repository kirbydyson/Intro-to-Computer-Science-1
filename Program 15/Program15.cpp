/*
*Author: Kirby Dyson
*Assignment Title: Multiplication Table
*Assignment Description: This program will ask the user to enter four
integers(r1,r2,c1,c2) and echo print it to the screen. It will then generate
and print to the screen a multiplication table that shows the multiplication
of integers  from r1 to r2(inclusive) by the integers c1 to c2 (inclusive).
*Due Date: 10/21/2022
*Date Created: 10/16/2022
*Date Last Modified: 10/19/2022
*/

/*
 * Data Abstraction:
         Eleven integers are initialized for use.
         A two-dimensional integer array is initialized for use
         with the max size being 25x25.
 * Input:
         Four integers are asked to be entered and are printed to the screen.
 *Process:
         The size of the row and column is calculated.
         The formula to multiply the integers is calculated and stored in
         the array.
 * Output:
         The multiplication table is printed to the screen.
 * Assumptions:
         It is assumed that there will be valid inputs.
 */


#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
    //Data Abstraction
    int data[25][25];
    int r1, r2, c1, c2;
    int r, c, i;
    int numR, numC;
    int rShift = 1, cShift = 1;



    //Input
    cin >> r1 >> r2 >> c1 >> c2;
    cout << "Please Enter Four Integers R1 R2 C1 C2: ";
    cout << r1 << " " << r2 << " " << c1 << " " << c2 << " " << endl;

    //Process
    numR = abs(r1 - r2) + 1;
    numC = abs(c1 - c2) + 1;

    if(r1 > r2) {
        rShift = -1;
    }
    if(c1 > c2) {
        cShift = -1;
    }

    for (r = 0; r < numR; r++){
        for (c = 0; c < numC; c++) {
            data[r][c] = (r1 + r * rShift) * (c1 + c * cShift);
        }
    }


    //Output
    cout << setw(9);
    for (i = 0; i < numC; i++) {
        cout << c1 << setw(6);
        c1 = c1 + cShift;
    }
    cout << endl;
    for (c = 0; c < numC + 1; c++) {
        cout << "-----|";
    }

    for (r = 0; r < numR; r++) {
        cout << endl;
        cout << r1 << "  ";
        r1 = r1 + rShift;
        for (c = 0; c < numC; c++) {
            cout << setw(6) << data[r][c];
            }
            cout << endl;
            for (c = 0; c < numC + 1; c++){
                cout << "-----|";
            }
    }


    return 0;
}

