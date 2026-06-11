#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

int linearSearch(vector<int>&nums, int target){
    for (int i = 0; i < nums.size(); i++){
        if(nums[i] == target){
            return i;
        }
    }
    return -1;
}
};

//T.C for this code is O(n) because whole array is traversed only one time and S.C is O(1) because no extra Data Structure is used, only loop variable i is used.