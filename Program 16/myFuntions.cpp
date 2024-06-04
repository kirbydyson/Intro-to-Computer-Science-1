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

#include "myFunctions.h"

int max(int a, int b){
    if(a < b) {
        a = b;
    }

    return a;
}

double max(double a, double b) {
    if(a < b) {
        a = b;
    }

    return a;
}

int max(int a[], int n) {
    int v;
    int i;

    v = a[0];
    for(i = 1; i < n; i++) {
        if (a[i] > v) {
            v = a[i];
        }
    }

    return v;
}

double max(double a[], int n){
    double v;
    int i;

    v = a[0];
    for(i = 1; i < n; i++) {
        if (a[i] > v) {
            v = a[i];
        }
    }

    return v;
}

int min(int a, int b) {
    if(a > b) {
        a = b;
    }

    return a;
}

double min(double a, double b) {
    if(a > b) {
        a = b;
    }

    return a;
}

int min(int a[], int n){
    int v;
    int i;

    v = a[0];
    for(i = 1; i < n; i++) {
        if (a[i] < v) {
            v = a[i];
        }
    }

    return v;
}

double min(double a[], int n){
    double v;
    int i;

    v = a[0];
    for(i = 1; i < n; i++) {
        if (a[i] < v) {
            v = a[i];
        }
    }

    return v;
}

int absoluteValue(int n) {
    if(n < 0) {
        n *= -1;
    }

    return n;
}

double absoluteValue(double n) {
    if(n < 0) {
        n *= -1;
    }

    return n;
}

double factorial(int n){
    double v = 1.0;


    while(n > 0) {
        v *= n;
        n--;
    }
    return v;
}

double combination(int m, int n) {
    double com;

    com = factorial(m) / (factorial(n) * factorial(m - n));

    return com;
}

double permutation(int m, int n) {
    double perm;

    perm = factorial(m) / factorial(m - n);

    return perm;
}
