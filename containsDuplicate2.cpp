#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> numsToArr(int num){
    vector<int> arr;
    //create array, number cannot end in 0
    while(num/10 > 0){ 
        arr.push_back(num % 10);
        num /= 10;
    }
    //reverse array
    int size = arr.size()/2;
    for(int i = 0; i < size; i++){
        int back = arr[size-i-1];
        int front = arr[i];
        arr[size-i-1] = front;
        arr[i] = back;
    }
    return arr;
}

bool checkDupe(vector<int> arr){
    map<int,int> table;
    for(int i = 0; i < arr.size(); i++){
        table[arr[i]] +=1;
        if(table[arr[i]]>1){
            return true;
        }
    }
    return false;
}

int main()
{
    int num;
    cout << "Enter array number";
    cin >> num;
    if(checkDupe(numsToArr(num))){
        cout << "yes duped";
    } else{
        cout << "no dupes";
    }

    return 0;
}
