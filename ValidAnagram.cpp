#include <iostream>
#include <map>
#include <string>
using namespace std;

map<char, int> stringToMap(string s1){
    map<char, int> mapS1;
    for(char i : s1){
        mapS1[i] += 1;
    }
    return mapS1;
}

void printMap(map<char, int> mapS1){
    for(const auto& charS : mapS1){
        cout<<"{"<<charS.first<<","<<charS.second<<"}"<<endl;
    }
}

bool isAnagram(string s1, string s2){
    if(s1.length() != s2.length()){
        return false;
    }
    map<char, int> mapS1 = stringToMap(s1);
    //assuming nums of types of char in s1 are all < s2 (s)
    for(char i : s2){
        if(mapS1[i] < 1){
            return false; 
        }
        mapS1[i] -= 1;
    }
    //assuming nums of types of char in s1 are all > s2 
    for(char i : s2){
        if(mapS1[i] > 0){
            return false;
        }
    }
    return true;
}


int main()
{
    string s1;
    string s2;
    cout<<"Enter first string here:";
    std::getline(std::cin, s1);
    cout<<"Enter second string here:";
    std::getline(std::cin, s2);
    map<char, int> mapS1 = stringToMap(s1);
    printMap(mapS1);
    if(isAnagram(s1,s2)){
        cout<<"s1 and s2 ARE anagrams";
    } else {
        cout<<"s1 and s2 ARE NOT anagrams";
    }
    printMap(mapS1);
    return 0;
}
