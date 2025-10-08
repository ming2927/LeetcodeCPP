#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> convertArr(long entry){
    vector<int> arr;
    while(entry > 0){
        arr.push_back(entry % 10);
        entry /= 10;
    }
    return arr;
}

map<int, int> freqNum(vector<int> arr){
    map<int, int> mapFreq;
    for(int i = 0; i < arr.size(); i++){
        mapFreq[arr[i]] ++;
    }
    return mapFreq; //key = number; value = frequency
}

vector<int> mostFreq(map<int, int> mapFreq, int k){
    vector<int> freqArr;
    int maxF = 0;
    int insertN;
    while(k > 0){
        for(const auto& num : mapFreq){
            if(num.second > maxF){
                maxF = num.second;
                insertN = num.first; 
            }
        }
        mapFreq.erase(insertN);
        freqArr.push_back(insertN);
        insertN = 0;
        maxF = 0;
        k --;
    }
    return freqArr;
}

void printArr(vector<int> arr){
    cout<<"[";
    for(int i = 0; i < arr.size(); i ++){
        cout<<arr[i]<<", ";
    }
    cout<<"]"<<endl;
}

void printMap(map<int, int> mapp){
    cout<<"["<<endl;
    for(const auto& num : mapp){
        cout<<"["<<num.first<<","<<num.second<<"]"<<endl;
    }
    cout<<"]"<<endl;
}

int main()
{
    long entry;
    int k;
    cout<<"Enter array of integers: ";
    cin>>entry;
    cout<<"Define k: ";
    cin>>k;
    vector<int> entryArr = convertArr(entry);
    //printArr(entryArr);
    map<int, int> mapFreqEntry = freqNum(entryArr);
    //printMap(mapFreqEntry);
    vector<int> resultK = mostFreq(mapFreqEntry, k);
    printArr(resultK);
}
