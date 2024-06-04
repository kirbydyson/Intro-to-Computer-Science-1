/*
*Author: Kirby Dyson
*Assignment Title: Array Processing
*Assignment Description: This program will implement a collection of
functions using a header file and an implementation file. It will place
the prototypes of the functions in a .h file, and implement these functions
in a .cpp file, using array processing skills.
*Due Date: 11/04/2022
*Date Created: 10/28/2022
*Date Last Modified: 11/02/2022
*/


#ifndef ARRAYCOUNT_H_INCLUDED
#define ARRAYCOUNT_H_INCLUDED
#include<iostream>
#include<vector>
using namespace std;
const int MAX_SIZE = 25;

/*
 *Description: arrayCount takes three parameters, and returns and integers.
 *Return: Integer
 *Precondition: An array of integers exist.
 *Postcondition: The frequency of the value v in the array a is returned.
 The original array is unchanged.
*/
int arrayCount(int a[], int s, int v);
/*
 *Description: arrayCount takes three parameters, and returns and integers.
 *Return: Integer
 *Precondition: An array of doubles exist.
 *Postcondition: The frequency of the value v in the array a is returned.
 The original array is unchanged.
*/
int arrayCount(double a[], int s, double v);
/*
 *Description: arrayCount takes three parameters, and returns and integers.
 *Return: Integer
 *Precondition: An array of strings exist.
 *Postcondition: The frequency of the value v in the array a is returned.
 The original array is unchanged.
*/
int arrayCount(string a[], int s, string v);
/*
 *Description: arrayCount takes two parameters, and returns and integers.
 *Return: Integer
 *Precondition: An array of characters exist.
 *Postcondition: The frequency of the value v in the array a is returned.
 The original array is unchanged.
*/
int arrayCount(char a[], char v);
/*
 *Description: arrayCount takes two parameters, and returns and integers.
 *Return: Integer
 *Precondition: A vector of integers exist.
 *Postcondition: The frequency of the value v in the array a is returned.
 The original vector is unchanged.
*/
int arrayCount(vector<int> a, int v);
/*
 *Description: arrayCount takes two parameters, and returns and integers.
 *Return: Integer
 *Precondition: A vector of strings exist.
 *Postcondition: The frequency of the value v in the vector a is returned.
 The original vector is unchanged.
*/
int arrayCount(vector<string> a, string v);
/*Description: arrayCount takes two parameters, and returns and integers.
 *Return: Integer
 *Precondition: A vector of doubles exist.
 *Postcondition: The frequency of the value v in the vector a is returned.
 The original vector is unchanged.
*/
int arrayCount(vector<double> a, double v);
/*
 *Description: arrayCount takes two parameters, and returns and integers.
 *Return: Integer
 *Precondition: A vector of character exist.
 *Postcondition: The frequency of the value v in the vector a is returned.
 The original vector is unchanged.
*/
int arrayCount(vector<char> a, char v);
/*
 *Description: matrixCount takes four parameters, and returns and integers.
 *Return: Integer
 *Precondition: A matrix of integers exist.
 *Postcondition: The frequency of the value v in the matrix m is returned.
 The original matrix is unchanged.
*/
int matrixCount(int m[][MAX_SIZE], int r, int c, int v);
/*
 *Description: matrixCount takes four parameters, and returns and integers.
 *Return: Integer
 *Precondition: A matrix of characters exist.
 *Postcondition: The frequency of the value v in the matrix m is returned.
 The original matrix is unchanged.
*/
int matrixCount(char m[][MAX_SIZE], int r, int c, char v);
/*
 *Description: matrixCount takes four parameters, and returns and integers.
 *Return: Integer
 *Precondition: A matrix of strings exist.
 *Postcondition: The frequency of the value v in the matrix m is returned.
 The original matrix is unchanged.
 */
int matrixCount(string m[][MAX_SIZE], int r, int c, string v);

#endif // ARRAYCOUNT_H_INCLUDED
