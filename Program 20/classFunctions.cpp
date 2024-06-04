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

#include "classFunctions.h"

void sortFirst(info a[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(a[j].first > a[j + 1].first){
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void sortLast(info a[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(a[j].last > a[j + 1].last){
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void sortGrade(info a[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(a[j].numGrade > a[j + 1].numGrade){
                swap(a[j], a[j + 1]);
            }
        }
    }
}


void sortGPA(info a[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(a[j].gpa > a[j + 1].gpa){
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void isDupe(info a[], int n){
    for(int i = 0; i < n; i++){
        if(i > 0 && a[i].first == a[i - 1].first
            && a[i].last == a[i - 1].last){
            a[i].dupe = true;
        }
    }
}

void info::Print(){
    if(!dupe){
        cout << first << setw(17) << last << setw(17);
        if(numGrade == 0){
            cout << "FR";
        }
        else if(numGrade == 1){
            cout << "SO";
        }
        else if(numGrade == 2){
            cout << "JR";
        }
        else if(numGrade == 3){
            cout << "SR";
        }
        cout << setw(17) << zip << setw(17) << age << setw(17) << town
        << setw(17) << fixed << setprecision(2) << gpa << setw(17) << endl;
    }
    else{
        cout << "I THINK THIS IS A DUPLICATE RECORD" << endl;
    }
}
