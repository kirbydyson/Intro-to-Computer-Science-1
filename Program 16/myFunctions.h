/*
*Author: Kirby Dyson
*Assignment Title: My Functions
*Assignment Description: This program will implement a number of useful
functions using a header file and an implementation file. It will place
the prototypes of the functions in a .h file, and implement these functions
in a .cpp file.
*Due Date: 10/28/2022
*Date Created: 10/24/2022
*Date Last Modified: 10/28/2022
*/

#ifndef MYFUNCTIONS_H_INCLUDED
#define MYFUNCTIONS_H_INCLUDED
#include<iostream>
using namespace std;

/*Precondition: Two integer values exist.
 *Postcondition: The value of the largest integer is returned.
 The original integers are unchanged. If the integers have the
 same value then the value of either integer is returned.
 *Return: Integer
 *Description: Function returns the value of the larger of two integers.
*/
int max(int, int);
/*Precondition: Two double value exist.
 *Postcondition: The value of the larger double is returned.
 The original doubles are unchanged. If the doubles have the
 same value then the value of either double is returned.
 *Return: Double
 *Description: Function returns the value of the larger of two doubles.
*/
double max(double, double);
/*Precondition: An array of integer values exist.
 *Postcondition: The largest value in the array is returned.
 The original array is unchanged.
 *Return: Integer
 *Description: Function returns the value of the largest integer in an array.
*/
int max(int[], int);
/*Precondition: An array of double values exist.
 *Postcondition: The largest value in the array is returned.
 The original array in unchanged.
 *Return: Double
 *Description: Function returns the value of the largest doubles in an array.
*/
double max(double[], int);
/*Precondition: Two integer values exist.
 *Postcondition: The value of the largest integer is returned.
 The original integers are unchanged. If the integers have the
 same value then the value of either integer is returned.
 *Return: Integer
 *Description: Function returns the value of the smaller of two integers.
*/
int min(int, int);
/*Precondition: Two double values exist.
 *Postcondition: The value of the smaller double is returned.
 The original double are unchanged. If the double have the
 same value then the value of either double is returned.
 *Return: Double
 *Description: Function returns the value of the smaller of two double.
*/
double min(double, double);
/*Precondition: An array of integer values exist.
 *Postcondition: The smallest value in the array is returned.
 The original array in unchanged.
 *Return: Integer
 *Description: Function returns the value of the smallest integer in an array.
*/
int min(int[], int);
/*Precondition: An array of double values exist.
 *Postcondition: The smallest value in the array is returned.
 The original array is unchanged.
 *Return: Double
 *Description: Function returns the value of the smallest doubles in an array.
*/
double min(double[], int);
/*Precondition: Some integer value exists.
 *Postcondition: Integer value is unchanged.
 *Return: Integer
 *Description: This function returns the absolute value of an integer.
*/
int absoluteValue(int);
/*Precondition: Some double value exists.
 *Postcondition: Double value is unchanged.
 *Return: Double
 *Description: This function returns the absolute value of a double.
*/
double absoluteValue(double);
/*Precondition: Some integer value N exists.
 *Postcondition: The value of the N is unchanged.
 *Return: Double
 *Description: The function calculates factorial.
*/
double factorial(int);
/*Precondition: Two integer value M and N exists.
 *Postcondition: The value of the M and N unchanged.
 *Return: The number of combinations of M items taken N at a time.
 *Description: The function calculates the number of combinations of M items.
 taken N at a time.
*/
double combination(int, int);
/*Precondition: Two integer value M and N exists.
 *Postcondition: The value of the M and N unchanged.
 *Return: The number of permutations of M items taken N at a time.
 *Description: The function calculates the number of permutations of M items
 taken N at a time.
*/
double permutation(int, int);

#endif // MYFUNCTIONS_H_INCLUDED
