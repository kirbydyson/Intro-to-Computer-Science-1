/*
* Author: Kirby Dyson
* Assignment Title: Matrix Arithmetic with objects
* Assignment Description: This program will construct a matrix_t class with
the given fields and methods. The max size of the matrix will be 100x100.
The matrix object will support the binary operations of addition, subtraction,
and multiplication.
* Due Date: 11/18/2022
* Date Created: 11/10/2022
* Date Last Modified: 11/17/2022
*/

#include "matrix.h"

matrix_t::matrix_t(){
    row = 0;
    col = 0;
}

matrix_t::matrix_t(int r, int c){
    row = r;
    col = c;
}

void matrix_t::setRow(int r){
    row = r;
}
void matrix_t::setCol(int c){
    col = c;
}

void matrix_t::setValue(int r, int c, double n){
    data[r][c] = n;
}

int matrix_t::getRow() const{
    return row;
}

int matrix_t::getCol() const{
    return col;
}

double matrix_t::getValue(int r, int c) const{
    return data[r][c];
}

void matrix_t::display(ostream& output) const{
    int r, c;
    for(r = 0; r < row; r++){
        for(c = 0; c < col; c++){
            output << data[r][c] << " ";
        }
        output << endl;
    }
}

matrix_t matrix_t::add(const matrix_t& other) const{
    int r, c;
    matrix_t result(row, col);
    for(r = 0; r < row; r++){
        for(c = 0; c < col; c++) {
            result.setValue(r, c, data[r][c] + other.data[r][c]);
        }
    }
    return result;
}

matrix_t matrix_t::subtract(const matrix_t& other) const{
    int r, c;
    matrix_t result(row, col);
    for(r = 0; r < row; r++){
        for(c = 0; c < col; c++){
            result.setValue(r, c, data[r][c] - other.data[r][c]);
        }
    }
    return result;
}

matrix_t matrix_t::multiply(const matrix_t& other) const{
    int r, c, i;
    matrix_t result(row, other.col);
    for(r = 0; r < row; r++){
        for(c = 0; c < other.col; c++){
            double mul = 0;
            for(i = 0; i < col; i++){
                mul += data[r][i] * other.data[i][c];
            }
            result.setValue(r, c, mul);
        }
    }
    return result;
}

matrix_t matrix_t::operator+(const matrix_t& other) const{
    return add(other);
}

matrix_t matrix_t::operator-(const matrix_t& other) const{
    return subtract(other);
}

matrix_t matrix_t::operator*(const matrix_t& other) const{
    return multiply(other);
}

double*  matrix_t::operator[](int n){
    return data[n];
}
