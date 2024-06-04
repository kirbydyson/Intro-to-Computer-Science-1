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

#include "arrayCount.h"


int arrayCount(int a[], int s, int v){
    int count = 0;
    int i;

    for(i = 0; i < s; i++) {
        if(a[i] == v) {
            count++;
        }
    }

    return count;
}

int arrayCount(double a[], int s, double v){
    int count = 0;
    int i;

    for(i = 0; i < s; i++) {
        if(a[i] == v) {
            count++;
        }
    }

    return count;
}

int arrayCount(string a[], int s, string v){
    int count = 0;
    int i;

    for(i = 0; i < s; i++) {
        if(a[i] == v) {
            count++;
        }
    }

    return count;
}

int arrayCount(char a[], char v){
    int count = 0;
    size_t i = 0;

    while(a[i] != '\0') {
        if(a[i] == v) {
            count++;
        }
        i++;
    }

    return count;
}

int arrayCount(vector<int> a, int v){
    int count = 0;
    size_t i = 0;

    for(i = 0; i < a.size(); i++) {
        if(a.at(i) == v) {
            count++;
        }
    }

    return count;

}

int arrayCount(vector<string> a, string v){
    int count = 0;
    size_t i = 0;

    for(i = 0; i < a.size(); i++) {
        if(a.at(i) == v) {
            count++;
        }
    }

    return count;

}

int arrayCount(vector<double> a, double v){
    int count = 0;
    size_t i = 0;

    for(i = 0; i < a.size(); i++) {
        if(a.at(i) == v) {
            count++;
        }
    }

    return count;

}

int arrayCount(vector<char> a, char v){
    int count = 0;
    size_t i = 0;

    for(i = 0; i < a.size(); i ++) {
        if(a.at(i) == v) {
            count++;
        }
    }

    return count;

}

int matrixCount(int m[][MAX_SIZE], int r, int c, int v){
    int count = 0;
    int i;
    int j;

    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            if(m[i][j] == v) {
                count++;
            }
        }
    }

    return count;

}

int matrixCount(char m[][MAX_SIZE], int r, int c, char v){
    int count = 0;
    int i;
    int j;

    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            if(m[i][j] == v) {
                count++;
            }
        }
    }

    return count;

}

int matrixCount(string m[][MAX_SIZE], int r, int c, string v){
    int count = 0;
    int i;
    int j;

    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            if(m[i][j] == v) {
                count++;
            }
        }
    }

    return count;

}
