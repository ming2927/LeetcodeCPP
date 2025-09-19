#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm> //implement own sort function later

using namespace std;

//method 2b - sort string by char a->z , use hashmap to return arrays of anagrams, o(log n)
//method 2b iteration 2 - implement custom sort function

//traverse array and sort all char of string elements
vector<string> sortarr(vector<string>& arr){
    for(int i = 0; i < arr.size(); i++){
        sort(arr[i].begin(), arr[i].end());
    }   
    return arr;
}

map<string, vector<int>> indexMap(vector<string>& arr){
    map<string, vector<int>> anagramidx;
    for(int i = 0; i < arr.size(); i++){
        anagramidx[arr[i]].push_back(i);
    }
    return anagramidx;
}

vector<vector<string>> groupAnagrams(map<string, vector<int>> mapIdx, vector<string>& originalArr){
    vector<vector<string>> grid(mapIdx.size()); // [[],[],[]]
    int gridIdx = 0;
    for(const auto& idx: mapIdx){
        vector<int> temp = idx.second;
        for(int i = 0; i < temp.size(); i++){
            grid[gridIdx].push_back(originalArr[temp[i]]);
        }
        gridIdx++;
    }
    return grid;
}

//prints array of anagrams
void printArray(vector<string>& arr){
    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<",";
    }
    cout<<endl; 
}

//takes user test input of anagram array, returns arrays of array strings
int main()
{
    vector<string> anagramArr;
    string sIn;
    for(int i = 0; i < 10; i++){
        cout<<"Enter string #"<<i<<": ";
        cin>>sIn;
        if(sIn == "end"){
            break;
        }
        anagramArr.push_back(sIn);
    }
    //prints [act, pots, tops, cat, stop, hat]
    printArray(anagramArr);
    vector<string> tempArr = anagramArr;
    vector<string> tempSortedArr = sortarr(tempArr);
    vector<vector<string>> resultAnagrams = groupAnagrams(indexMap(tempSortedArr), anagramArr);
    //print 2D result array;
    for(int i = 0; i < resultAnagrams.size(); i++){
        cout<<"{";
        for(int j = 0; j < resultAnagrams[i].size(); j++){
            cout<<resultAnagrams[i][j]<<",";
        }
        cout<<"}"<<endl;
    }

    return 0;
}
