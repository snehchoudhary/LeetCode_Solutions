#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

int majorityElement(vector<int>&nums) {
    int candidate = 0;
    int count = 0;

    for (int num: nums){
        if ( count == 0 ){
            candidate = num;
        }
        if (num == candidate){
            count++;
        }
        else{
            count--;
        }
    }
    return candidate;
}
};

//In Qn it was asked to find element which has highest frequency in array so we used BOYER - MOORE VOTING ALGO : finds majority element by cancelling out different elements.

//T.C : O(n) -->> one loop through array
//S.C : O(1) -->> int candidate & int count