//non-optimal, O(N^2) solution

#include <iostream>
#include <vector>
using namespace std;

int size = 0;

vector<int> convertNumToArray(int num){
    //takes user input to make array for test case
    int temp = num;
    //int size = 0;
    while(temp > 0){
        temp /= 10;
        size++;
    }
    vector<int> convertedArray(size);
    for(int i = 0; i < size; i++){
        convertedArray[i] = num % 10;
        num /= 10;
    }
    
    //reverse array to unflip nums for clear output
    for(int i = 0; i < size/2; i++){
        int front = convertedArray[i];
        int back = convertedArray[size - 1- i];
        convertedArray[i] = back;
        convertedArray[size-1-i] = front;
    }
    return convertedArray;
}

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result(2);
    for(int i = 0; i < size-1; i++){
        for(int j = i+1; j < size; j++){
            if(nums[i]+nums[j]==target){
                result[0] = i;
                result[1] = j;
                return result;                
            }
        }
    }
    return result;
}

void print(vector<int>& array){
    int size = array.size();
    for(int i = 0; i < size; i++){
        std::cout<<array[i]<<",";
    }
}

int main()
{
    int userInput;
    std::cout<<"Enter a number";
    std::cin>>userInput;
    int target;
    std::cout<<"Enter a target sum";
    std::cin>>target;
    vector<int> numArray = convertNumToArray(userInput);
    vector<int> resultTwoSum = twoSum(numArray, target);
    print(numArray);
    std::cout<<std::endl;
    print(resultTwoSum);
    //std::cout<<"your input "<<print(numArray)<<" contains "<<print(resultTwoSum)<<" meeting target "<<target;
    return 0;
}
