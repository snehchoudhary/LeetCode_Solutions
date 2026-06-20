//Given an integer array nums, handle multiple queries of the following type:

//Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
//Implement the NumArray class:

//NumArray(int[] nums) Initializes the object with the integer array nums.
//int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).


#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//brute force approach:
class NumArray {
public:

    vector <int> nums;
    
    NumArray(vector<int>& nums) {
        this -> nums = nums;
    }
    
    int sumRange(int left, int right) {
        int sum = 0;

        for (int i = left; i <= right; i++){
            sum += nums[i];
        }
        return sum;
    }
};

//optimal approach:
class NumArray {
public:

    vector<int>prefix;

    NumArray(vector<int>& nums) {
        prefix.resize(nums.size());
        prefix[0] = nums[0];

        for (int i =1; i < nums.size(); i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0){
            return prefix[right];
        }
        return prefix[right] - prefix[left - 1];
    }
};