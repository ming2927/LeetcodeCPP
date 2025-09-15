#include <iostream>
#include <vector>
#include <map>
using namespace std;

//convert nums to array
vector<int> convertNumToArray(int n){
    vector<int> numArray;
    while (n > 0){
        numArray.push_back(n % 10); //add ints in reverse order to array
        n /= 10;
    }
    //flip array to original order
    for(int i = 0; i < numArray.size()/2; i++){
        int front = numArray[i];
        int back = numArray[numArray.size() - 1 - i];
        numArray[i] = back;
        numArray[numArray.size() - 1 - i] = front;
    }
    return numArray;
}

//prints array
void printArray(vector<int> arrayToPrint){
    for(int i = 0; i < arrayToPrint.size(); i++){
        cout << arrayToPrint[i]<<",";
    }
    cout << endl;
}

//checks if array contains duplicate
bool containsDuplicate(vector<int> numArray){
    int size = numArray.size();
    map<int, int> checkDupe;
    for(int i = 0; i < size; i++){
        checkDupe[numArray[i]] += 1;
        if(checkDupe[numArray[i]] > 1){
            return true;
        }
    }
    return false;
}

int main()
{
    int test;
    cout << "Enter num array";
    cin >> test;
    printArray(convertNumToArray(test));
    if(containsDuplicate(convertNumToArray(test))){
        cout << "contains duplicate";
    } else {
        cout << "does not contain duplicate";
    }
    return 0;
}
