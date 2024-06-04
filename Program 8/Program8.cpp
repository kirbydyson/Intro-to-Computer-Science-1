/*
*Author: Kirby Dyson
*Assignment Title: Quadratic Formula
*Assignment Description: In this program both roots of a quadratic
equation will be calculated. The user will input a, b, and c and print
both roots to the screen. The roots will be ordered from least to greatest.
If the quadratic equation has a negative discriminant the program will
output "NO REAL ROOTS". If two roots are the same, only one will print to
the screen. The vertex of the parabola will also be calculated and printed
to the screen.
*Due Date: 9/21/2022
*Date Created: 9/14/2022
*Date Last Modified: 9/19/2022
*/

/*
 * Data Abstraction:
         One integer, numRoots, is initialized for use.
         Eight doubles, a, b, c, d, root1, root2, vertex1,
         and vertex2, are initialized for use.
 * Input:
         The program inputs three numbers known as a, b, c.
 * Process:
         Root1, root2, vertex1, and vertex2 are calculated.
         The roots are ordered from least to greatest.
 * Output:
         If the quadratic equation contained a negative discriminant,
         "NO REAL ROOTS" is printed to the screen.
         If two roots are the same, root1 will print to the screen, if
         not, root2 will also print to the screen.
         The vertex is printed to the screen.
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
    int numRoots;
    double a;
    double b;
    double c;
    double d;
    double root1;
    double root2;
    double vertex1;
    double vertex2;

    //Input
    cin >> a;
    cin >> b;
    cin >> c;

    //Process
    d = ((b * b) - (4 * a * c));
    root1 = (((-1 * b) - sqrt(d)) / (2 * a));
    root2 = (((-1 * b) + sqrt(d)) / (2 * a));
    vertex1 = ((-1 * b) / (2 * a));
    vertex2 = (a * (pow(vertex1 , 2))) + (b * vertex1) + c;
    if (d > 0) {
        numRoots = 2;
    }
    else if (d == 0) {
        numRoots = 1;
    }
    else {
        numRoots = 0;
    }
    if (root1 == -0) {
        root1 = 0;
    }
    if (root2 == -0) {
        root2 = 0;
    }
    if (vertex1 == -0) {
        vertex1 = 0;
    }
    if (vertex2 == -0) {
        vertex2 = 0;
    }
    if (root1 > root2) {
        swap (root1 , root2);
    }


    //Output
    cout << fixed << setprecision(2);
    if (numRoots == 0) {
        cout << "NO REAL ROOTS";
    }
    else {
        cout << root1;
    }
    if (numRoots == 2) {
        cout << " " << root2;
    }
    cout << " (" << vertex1 << "," << vertex2 << ")" << endl;

    return 0;
}
