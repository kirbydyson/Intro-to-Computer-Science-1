#include <iostream>
#include <cmath>
using namespace std;
main()
{
    int avgStartH, avgStartM, avgStartS;
    int avgStopH, avgStopM, avgStopS;
    int totalStartSec = 43240;
    int totalStopSec = 76389;
    int avgStartSec, avgStopSec;


    avgStartH = totalStartSec / 3600;
    avgStartM = avgStartH / 60;
    avgStartS = totalStartSec - avgStartH - avgStartM;
    avgStopH = totalStopSec / 3600;
    avgStopM = avgStopH / 60;
    avgStopS = totalStopSec - avgStopH - avgStopM;

    cout << avgStartH << endl;
    cout << avgStartM << endl;
    cout << avgStartS << endl;
    cout << avgStopH << endl;
    cout << avgStopM << endl;
    cout << avgStopS << endl;

    return 0;
}
