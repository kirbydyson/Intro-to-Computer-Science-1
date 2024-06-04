/*
* Author: Kirby Dyson
* Assignment Title: Sorting Students
* Assignment Description: This program will open a file named stDATA.txt and
print a list of students sorted by GPA. If two students have the same GPA
they will be sorted by classification, if they have the same GPA and
classification they will be sorted by last name, and if the GPA,
classification, and last name are the same they will be sorted by first name.
Three files, main.cpp, classFunctions.h, and classFunctions.cpp will be used.
* Due Date: 12/02/2022
* Date Created: 11/18/2022
* Date Last Modified: 12/02/2022
*/

#ifndef CLASSFUNCTIONS_H_INCLUDED
#define CLASSFUNCTIONS_H_INCLUDED

#include<iostream>
#include<string>
#include<ostream>
#include<iomanip>

using namespace std;

struct info{
    string first;
    string last;
    string town;
    int zip;
    int age;
    int numGrade;
    double gpa;
    bool dupe = false;

    /*
     *Precondition: Information exists in a file.
     *Postcondition: The students record or the message
     "I THINK THIS IS A DUPLICATE RECORD" is printed.
     *Return: Void
     *Description: The students records are printed.
    */
    void Print();
};

/*
 *Precondition: An array exists.
 *Postcondition: The first names are sorted.
 *Return: Void
 *Description: An array takes two parameters and is sorted by first name.
*/
void sortFirst(info[], int);

/*
 *Precondition: An array exists.
 *Postcondition: The last names are sorted.
 *Return: Void
 *Description: An array takes two parameters and is sorted by last name.
*/
void sortLast(info[], int);

/*
 *Precondition: An array exists.
 *Postcondition: The grade/classification is sorted.
 *Return: Void
 *Description: An array takes two parameters and is sorted by classification.
*/
void sortGrade(info[], int);

/*
 *Precondition: An array exists.
 *Postcondition: The gpa is sorted.
 *Return: Void
 *Description: An array takes two parameters and is sorted by gpa.
*/
void sortGPA(info[], int);
/*
 *Precondition: An array exists.
 *Postcondition: The duplicates are found.
 *Return: Void
 *Description: An array takes two parameters and finds the duplicates.
*/
void isDupe(info[], int);

#endif // CLASSFUNCTIONS_H_INCLUDED
