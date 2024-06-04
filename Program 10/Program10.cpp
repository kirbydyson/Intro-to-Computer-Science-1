/*
* Author: Kirby Dyson
* Assignment Title: Average Start and Stop Time
* Assignment Description: This program will calculate and display the average
start and stop time for three events. Each events start and stop time will be
stored in a file. Each file will open and read the start and stop time. After
reading all the data the program will calculate and display the average start
and stop time. If any file fails to open, an error message will print to the
screen.
* Due Date: 9/28/2022
* Date Created: 9/21/2022
* Date Last Modified: 9/28/2022
*/

/*
 * Data Abstraction:
         Twelve strings are initialized for use.
         One ifstream, one char, and one bool are initialized for use.
         Twenty-four integers are initialized for use.
 * Input:
         The program inputs and opens three files. If a file fails to open,
         the bool is assigned to true. The start and stop times are stored
         in the files. The input files are closed.
 * Process:
         The hours, minutes, and seconds are converted to seconds and then
         back to hours, minutes, and seconds. The average start and stop time
         is found and rounded to the nearest minute. Depending on the time,
         "AM" and "PM" are calculated and added to the start and stop times.
 * Output:
         If the files do not open, an error message is printed.
         If the files do open, the average start and stop times are
         printed to the screen.
 * Assumptions:
         It is assumed that there will be three file inputs.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    //Data Abstraction
    string fileName1, fileName2, fileName3;
    string st1_ampm, stop1_ampm;
    string st2_ampm, stop2_ampm;
    string st3_ampm, stop3_ampm;
    string totalSt_ampm, totalStop_ampm;
    string junk;
    ifstream inFile1, inFile2, inFile3;
    int stH1, stH2, stH3;
    int stM1, stM2, stM3;
    int stS1, stS2, stS3;
    int stopH1, stopH2, stopH3;
    int stopM1, stopM2, stopM3;
    int stopS1, stopS2, stopS3;
    int totalStH, totalStM, totalStS;
    int totalStopH, totalStopM, totalStopS;
    char c;
    bool badFile = false;


    //Input
    cin >> fileName1;
    cin >> fileName2;
    cin >> fileName3;

    inFile1.open(fileName1);
    inFile2.open(fileName2);
    inFile3.open(fileName3);

    if(!inFile1.is_open() || !inFile2.is_open() || !inFile3.is_open()){
        badFile = true;
    }

    inFile1 >> junk >> stH1 >> c >> stM1 >> c >> stS1 >> st1_ampm;
    inFile1 >> junk >> stopH1 >> c >> stopM1 >> c >> stopS1 >> stop1_ampm;

    inFile2 >> junk >> stH2 >> c >> stM2 >> c >> stS2 >> st2_ampm;
    inFile2 >> junk >> stopH2 >> c >> stopM2 >> c >> stopS2 >> stop2_ampm;

    inFile3 >> junk >> stH3 >> c >> stM3 >> c >> stS3 >> st3_ampm;
    inFile3 >> junk >> stopH3 >> c >> stopM3 >> c >> stopS3 >> stop3_ampm;

    inFile1.close();
    inFile2.close();
    inFile3.close();

    //Process
    stH1 %= 12;
    stH2 %= 12;
    stH3 %= 12;
    stopH1 %= 12;
    stopH2 %= 12;
    stopH3 %= 12;

    if (st1_ampm == "PM"){
        stH1 += 12;
    }
    if (st2_ampm == "PM"){
        stH2 += 12;
    }
    if (st3_ampm == "PM"){
        stH3 += 12;
    }
    if (stop1_ampm == "PM"){
        stopH1 += 12;
    }
    if (stop2_ampm == "PM"){
        stopH2 += 12;
    }
    if (stop3_ampm == "PM"){
        stopH3 += 12;
    }

    totalStS = ((stH1 + stH2 + stH3) * 3600)
    + ((stM1 + stM2 + stM3) * 60)
    + (stS1 + stS2 + stS3);

    totalStS = ceil(totalStS / 3.0);

    totalStopS = ((stopH1 + stopH2 + stopH3) * 3600)
    + ((stopM1 + stopM2 + stopM3) * 60)
    + (stopS1 + stopS2 + stopS3);

    totalStopS = ceil(totalStopS / 3.0);

    totalStH = (totalStS / 3600);
    totalStS = (totalStS - (totalStH * 3600));
    totalStM = (totalStS / 60);
    totalStS = (totalStS - (totalStM * 60));

    totalStopH = (totalStopS / 3600);
    totalStopS = (totalStopS - (totalStopH * 3600));
    totalStopM = (totalStopS / 60);
    totalStopS = (totalStopS - (totalStopM * 60));


    if (totalStH >= 12) {
        totalStH %= 12;
        totalSt_ampm = "PM";
    }
    else {
        totalSt_ampm = "AM";
    }
    if (totalStH == 0) {
        totalStH = 12;
    }
    if (totalStopH >= 12) {
        totalStopH %= 12;
        totalStop_ampm = "PM";
    }
    else {
        totalStop_ampm = "AM";
    }
    if (totalStopH == 0) {
        totalStopH = 12;
    }
    if (totalStopS > 0) {
        totalStopM += 1;
    }

    //Output
    if (badFile) {
        cout << "Error: At Least One File Failed to Open." << endl;
    }
    else {
        cout << "Average Start Time: " << totalStH << c;
        if (totalStM < 10) {
            cout << "0";
        }
        cout << totalStM << c;
        cout << "00" << " ";
        cout << totalSt_ampm;
        cout << endl;

        cout << "Average Stop Time: " << totalStopH << c;
        if (totalStopM < 10) {
            cout << "0";
        }
        cout << totalStopM << c;
        cout << "00" << " ";
        cout << totalStop_ampm;
        cout << endl;
    }
    return 0;
}

