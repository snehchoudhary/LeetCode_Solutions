//Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

//The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

//You must write an algorithm that runs in O(n) time and without using the division operation.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int>left(n, 1);
        vector<int>right(n, 1);
        vector<int>answer(n);

        //build left product
        for (int i = 1; i < nums.size(); i++){
            left[i] = left[i-1] * nums[i-1];
        }
        //build right product
        for (int i = nums.size()-2; i>=0; i-- ){
            right[i] = right[i+1] * nums[i+1];
        }
        //multiply both
        for (int i = 0; i < nums.size(); i++){
            answer[i] = left[i] * right[i];
        }
        return answer;
    }
};