#include<iostream>
#include<vector>
using namespace std;

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

int main() {
    char a[] = {'k','k','d','c','\0'};
    int v = 'k';

    if(arrayCount(a,v)== 2){
        cout << "pass" << endl;
    }


return 0;
}











