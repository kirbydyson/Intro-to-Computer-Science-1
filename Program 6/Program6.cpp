/*
*Author: Kirby Dyson
*Assignment Title: Report Min Max Median
*Assignment Description: In this program the user will enter 5 test scores,
sort the scores, and then calculate their min, max, and median.
The min, max, and median will then print to the screen.
*Due Date: 9/14/2022
*Date Created: 9/9/2022
*Date Last Modified: 9/10/2022
*/

/*
 * Data Abstraction:
         Five doubles, n1, n2, n3, n4, n5, are initialized for use.
 * Input:
         The program inputs five numbers known as n1, n2, n3, n4,
         and n5.
         The five numbers are then printed to the screen.
 * Process:
         The five numbers are sorted from least to greatest.
 * Output:
         The mix, max, and median are printed to the screen.
 * Assumptions:
         It is assumed that there will be valid inputs.
 */

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    //Data Abstraction
    double n1;
    double n2;
    double n3;
    double n4;
    double n5;

    //Input
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

    //Output
    cout << endl;
    cout << "Min = " << n1 << endl;
    cout << "Median = " << n3 << endl;
    cout << "Max = " << n5 << endl;

    return 0;
}
