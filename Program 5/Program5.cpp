/*
*Author: Kirby Dyson
*Assignment Title: Arithmetic Mean, Geometric Mean, Harmonic Mean,
& Standard Deviation
*Assignment Description: In this program the user will enter 5 integers
then calculate their arithmetic mean, geometric mean, harmonic mean, and
standard deviation. The integers will then print, label, and sort from
greatest to least the numbers and four statistics.
*Due Date: 9/9/2022
*Date Created: 9/5/2022
*Date Last Modified: 9/9/2022
*/

/*
 * Data Abstraction:
         Five integers, num1, num2, num3, num4, and num5 are initialized
         for use.
         Four long doubles, arithmeticMean, geometricMean, harmonicMean,
         and standardDeviation are initialized for use.
 * Input:
         The program inputs five numbers known as num1, num2, num3, num4,
         and num5.
         The five numbers are then printed to the screen.
 * Process:
         The five integers are sorted from greatest to least.
         The arithmetic mean, geometric mean, harmonic mean, and standard
         deviation are calculated.
 * Output:
         The five sorted integers are printed from greatest to least.
         The arithmetic mean, geometric mean, harmonic mean, and standard
         deviation are printed to the screen.
 * Assumptions:
         It is assumed that there will be valid inputs
 */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    //Data Abstraction
    int num1;
    int num2;
    int num3;
    int num4;
    int num5;
    long double arithmeticMean;
    long double geometricMean;
    long double harmonicMean;
    long double standardDeviation;

    //Input
    cout << "Enter five numbers:" << endl;
    cin >> num1;
    cout << num1 << endl;
    cin >> num2;
    cout << num2 << endl;
    cin >> num3;
    cout << num3 << endl;
    cin >> num4;
    cout << num4 << endl;
    cin >> num5;
    cout << num5 << endl;
    cout << endl;

    //Process
    if (num1 < num2) {
        swap (num1 , num2);
    }
    if (num1 < num3) {
        swap (num1 , num3);
    }
    if (num1 < num4) {
        swap (num1 , num4);
    }
    if (num1 < num5) {
        swap (num1 , num5);
    }
    if (num2 < num3) {
        swap (num2 , num3);
    }
    if (num2 < num4) {
        swap (num2 , num4);
    }
    if (num2 < num5) {
        swap (num2, num5);
    }
    if (num3 < num4) {
        swap (num3 , num4);
    }
    if (num3 < num5) {
        swap (num3 , num5);
    }
    if (num4 < num5) {
        swap (num4 , num5);
    }
    arithmeticMean = ((num1 + num2 + num3 + num4 + num5) / 5.0);
    geometricMean = pow(1.0 * num1 * num2 * num3 * num4 * num5 , 1.0/5.0);
    harmonicMean = (5.0 / ((1.0/num1) + (1.0/num2) + (1.0/num3) + (1.0/num4)
    + (1.0/num5)));
    standardDeviation = pow(arithmeticMean - num1 , 2.0);
    standardDeviation = standardDeviation + pow(num2 - arithmeticMean , 2.0);
    standardDeviation = standardDeviation + pow(num3 - arithmeticMean , 2.0);
    standardDeviation = standardDeviation + pow(num4 - arithmeticMean , 2.0);
    standardDeviation = standardDeviation + pow(num5 - arithmeticMean , 2.0);
    standardDeviation = sqrt(standardDeviation / 5);

    //Output
    cout << "Result:" << endl;
    cout << endl;
    cout << "Data:" << endl;
    cout << num1 << endl << num2 << endl << num3 << endl << num4 <<
    endl << num5 << endl;
    cout << endl;
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << arithmeticMean << endl;
    cout << "Geometric Mean = " << geometricMean << endl;
    cout << "Harmonic Mean = " << harmonicMean << endl;
    cout << "Standard Deviation = " << standardDeviation << endl;

    return 0;
}
