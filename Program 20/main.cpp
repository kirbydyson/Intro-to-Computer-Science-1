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

/*
 * Data Abstraction:
         Six strings are initialized for use.
         Three integers are initialized for use.
         One double, one ifstream, and one array are initialized for use.
 * Input:
         The program inputs and opens a file. The data is read from the file
         after one line is skipped. The data is stored in the array by each
         line. The input file is closed.
 * Process:
         The information is sorted by GPA, classification, last name, and
         first name. If all of the information is the same, it is a duplicate
         record.
 * Output:
         The students sorted record will be printed to the screen.
 * Assumptions:
         It is assumed that there will be a valid input file.
 */

#include <iostream>
#include<fstream>
#include<string>
#include "classFunctions.h"

using namespace std;

const int SIZE = 100;

int main()
{
    // Data Abstraction
    string first, last, town, grade;
    string line;
    string file = "stDATA.txt";
    int zip, age;
    int count = 0;
    double gpa;
    info a[SIZE];
    ifstream inFile;

    // Input
    inFile.open(file);

    getline(inFile, line);

    while(inFile >> first){
        inFile >> last;
        inFile >> grade;
        inFile >> zip;
        inFile >> age;
        inFile >> town;
        inFile >> gpa;


        a[count].first = first;
        a[count].last = last;
        a[count].zip = zip;
        a[count].age = age;
        a[count].town = town;
        a[count].gpa = gpa;

        if(grade == "FR"){
            a[count].numGrade = 0;
        }
        else if(grade == "SO"){
            a[count].numGrade = 1;
        }
        else if(grade == "JR"){
            a[count].numGrade = 2;
        }
        else if(grade == "SR"){
            a[count].numGrade = 3;
        }


        count++;
    }

    inFile.close();

    // Process
    sortFirst(a, count);
    sortLast(a, count);
    sortGrade(a, count);
    sortGPA(a, count);
    isDupe(a, count);


    // Output
    cout << left << setw(17) << "First Name" << setw(17) << "Last Name" <<
    setw(17) << "CLASS" << setw(17) << "ZIP" << setw(17) << "AGE" <<
    setw(17) << "HomeTown" << setw(17) << "GPA" << endl;

    for(int i = 0; i < count; i++){
        a[i].Print();
    }

    return 0;
}
