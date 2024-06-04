/*
* Author: Kirby Dyson
* Assignment Title: Sum The Digits In An Integer
* Assignment Description: This program reads an
integer between 0 and 9999999 and sums the digits
in the integer.
* Due Date: 9/2/2022
* Date Created: 9/1/2022
* Date Last Modified: 9/2/2022
*/

/*
 * Data Abstraction:
         Two variables, n and sum, are initialized for use
         The variable sum is assigned to 0
 * Input:
         The program inputs an integer between 0 and 9999999,
         known as "n" and then "n" is printed to the screen
 * Process:
         The sum of the integer "n" is calculated
 * Output:
         The sum of the integer "n" is printed to the screen
 * Assumptions:
         It is assumed that there will be a valid input
 */

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    // Data Abstraction
    int n;
    int sum = 0;

    //Input
    cout << "Enter an integer between 0 and 9999999: ";
    cin >> n;
    cout << n << endl;

    //Process
    sum += n % 10;
    n /= 10;
    sum += n % 10;
    n /= 10;
    sum += n % 10;
    n /= 10;
    sum += n % 10;
    n /= 10;
    sum += n % 10;
    n /= 10;
    sum += n % 10;
    n /= 10;
    sum += n % 10;
    n /= 10;

    //Output
    cout << "The sum of the digits is " << sum << "." << endl;

    return 0;
}
