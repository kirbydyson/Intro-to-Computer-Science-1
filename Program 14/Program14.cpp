/*
*Author: Kirby Dyson
*Assignment Title: Array Backwards
*Assignment Description: This program will read an unknown amount of integers
into an array and display it in reverse order. The user will be asked for the
number of integers to read, read the number of integers, and store it in the
array. The input will be echo printed to the screen. The sum of all elements
of the array, the total number of duplicate elements in the array, and the
maximum and minimum elements in the array will be reported.
*Due Date: 10/12/2022
*Date Created: 10/07/2022
*Date Last Modified: 10/12/2022
*/

/*
 * Data Abstraction:
         Six integers are initialized for use.
         One size_t, integer vector, and bool are initialized for use.
 * Input:
         The user is asked for the number of integer values to read, they are
         read and stored in the array. The values are echo printed to the
         screen.
 *Process:
         The minimum, maximum, sum, and total number of duplicates in the
         array are determined.
 * Output:
         The values stored in the array in normal and reverse order will be
         printed to the screen. The sum, number of duplicates, minimum, and
         maximum will be printed to the screen.
 * Assumptions:
         It is assumed that there will be valid inputs
 */


#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 2500;
int main()
{
    //Data Abstraction
    int n;
    int min;
    int max;
    int sum = 0;
    int nums[SIZE];
    vector<int> list;
    bool onList;

    //Input
    cout << "Input the number of elements to store in the array: ";
    cin >> n;
    cout << n << endl;
    cout << "Input " << n << " integers:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        cout << "integer - " << i << " : " << nums[i] << endl;
    }
    cout << endl;

    //Process
    min = nums[0];
    max = nums[0];
    for(int i = 0; i < n; i++) {
        if(nums[i] < min) {
            min = nums[i];
        }
        if(nums[i] > max) {
            max = nums[i];
        }
        sum += nums[i];
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(nums[i] == nums[j]){
                onList = false;
                for(size_t k = 0; k < list.size(); k++){
                    if(list.at(k) == nums[i]){
                        onList = true;
                    }
                }
                if(!onList){
                    list.push_back(nums[i]);
                }
            }
        }
    }


    //Output
    cout << "The values stored into the array are : " << endl;
    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl << endl;

    cout << "The values stored into the array in reverse are : " << endl;
    for(int i = n - 1; i >= 0; i--) {
        cout << nums[i] << " ";
    }
    cout << endl << endl;

    cout << "The sum of all elements of the array is "
    << sum << endl;
    cout << "The total number of duplicate elements in the array is "
    << list.size() << endl;
    cout << "The maximum and minimum element in the array are "
    << max << " , " << min << endl;

    return 0;
}


