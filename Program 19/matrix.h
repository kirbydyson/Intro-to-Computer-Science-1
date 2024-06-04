/*
* Author: Kirby Dyson
* Assignment Title: Matrix Arithmetic with objects
* Assignment Description: This program will construct a matrix_t class with
the given fields and methods. The max size of the matrix will be 100x100.
The matrix object will support the binary operations of addition, subtraction,
and multiplication.
* Due Date: 11/18/2022
* Date Created: 11/10/2022
* Date Last Modified: 11/15/2022
*/

#ifndef MATRIXDEC_H_INCLUDED
#define MATRIXDEC_H_INCLUDED

#include <ostream>
using namespace std;

const int MAX_SIZE = 100;
const int WIDTH = 4;

class matrix_t{
private:
	int row, col;
	double data[MAX_SIZE][MAX_SIZE] = {{0}};

public:
    /*
     *Description: Default constructor
     *Return: Matrix
     *Precondition: A matrix object exists
     *Postcondition: The default values for row and col are set
    */
	matrix_t();
    /*
     *Description: Custom constructor
     *Return: Matrix
     *Precondition: Two integer values exist
     *Postcondition: The custom values for row and col are set
    */
	matrix_t(int, int);
    /*
     *Description: Mutator method to set the value of row
     *Return: Void
     *Precondition: One integer value exists
     *Postcondition: The value for row is set
    */
	void setRow(int);
    /*
     *Description: Mutator method to set the value of col
     *Return: Void
     *Precondition: One integer value exists
     *Postcondition: The value for col is set
    */
	void setCol(int);
    /*
     *Description: Mutator method to set a cell in the Matrix
     *Return: Void
     *Precondition: Two integer values and one double value exists
     *Postcondition: The values for the matrix is set
    */
	void setValue(int, int, double);
    /*
     *Description: Accessor method to return the value of row
     *Return: Integer
     *Precondition: A matrix object exists
     *Postcondition: The value for row is returned
    */
	int getRow() const;
    /*
     *Description: Accessor method to return the value of col
     *Return: Integer
     *Precondition: A matrix object exists
     *Postcondition: The value for col is returned
    */
	int getCol() const;
    /*
     *Description: Accessor method to return the value of a cell in the matrix
     *Return: Double
     *Precondition: Two integer values exist
     *Postcondition: The values for the matrix is returned
    */
	double getValue(int, int) const;
    /*
     *Description: Member function to write matrix to an ostream
     *Return: Void
     *Precondition: A matrix object exists
     *Postcondition: The matrix is output to an ostream
    */
	void display(ostream&) const;
    /*
     *Description: Member function to add two matrices
     *Return: Matrix
     *Precondition: A matrix object exists
     *Postcondition: Two matrices are added
    */
	matrix_t add(const matrix_t&) const;
    /*
     *Description: Member function to subtract two matrices
     *Return: Matrix
     *Precondition: A matrix object exists
     *Postcondition: Two matrices are subtracted
    */
	matrix_t subtract(const matrix_t&) const;
    /*
     *Description: Member function to multiply two matrices
     *Return: Matrix
     *Precondition: A matrix object exists
     *Postcondition: Two matrices are multiplied
    */
	matrix_t multiply(const matrix_t&) const;
    /*
     *Description: Overloaded addition operator
     *Return: Matrix
     *Precondition: A matrix object exists
     *Postcondition: The added matrices are returned
    */
	matrix_t operator+(const matrix_t&) const;
    /*
     *Description: Overloaded subtraction operator
     *Return: Matrix
     *Precondition: A matrix object exists
     *Postcondition: The subtracted matrices are returned
    */
	matrix_t operator-(const matrix_t&) const;
    /*
     *Description: Overloaded multiplication operator
     *Return: Matrix
     *Precondition: A matrix object exists
     *Postcondition: The multiplied matrices are returned
    */
	matrix_t operator*(const matrix_t&) const;
    /*
     *Description: Overloaded square brackets
     *Return: Double
     *Precondition: One integer value exists, square brackets are used
     *Postcondition: The data at position n is returned
    */
	double*  operator[](int n);

};


#endif // MATRIXDEC_H_INCLUDED
