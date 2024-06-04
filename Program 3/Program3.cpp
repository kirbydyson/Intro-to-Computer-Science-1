/*
*Author: Kirby Dyson
*Assignment Title: Complex Numbers
*Assignment Description: This program displays the results of
adding, subtracting, multiplying, and dividing two
imaginary numbers
*Due Date: 8/31/2022
*Date Created: 8/30/2022
*Date Last Modified: 8/31/2022
*/


#include <iostream>
#include <iomanip>
using namespace std;
int main()
{

    double a;
    double b;
    double c;
    double d;
    double a1;
    double b1;
    double a2;
    double b2;
    double a3;
    double b3;
    double a4;
    double b4;
    double a5;
    double b5;
    double a6;



    a = 1.2;
    b = -3;
    c = -5.7;
    d = 6.3;
    a1 = a + c;
    b1 = b + d;
    a2 = a - c;
    b2 = b - d;
    a3 = (a * c) - (b * d);
    b3 = (a * d) + (b * c);
    a4 = (a * c) + (b * d);
    b4 = (b * c) - (a * d);
    a5 = (c * c) + (d * d);
    b5 = (a4 / a5);
    a6 = (b4 / a5);


    cout << fixed << setprecision(1);
    cout << "n1 + n2 = " << a1 << " + " << b1 << "i" <<  endl;
    cout << "n1 - n2 = " << a2 << " + " << b2 << "i" << endl;
    cout << "n1 * n2 = " << a3 << " + " << b3 << "i" << endl;
    cout << "n1 / n2 = " << b5 << " + " << a6 << "i" << endl;

    return 0;
}

