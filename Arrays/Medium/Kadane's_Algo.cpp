//Given an integer array nums, find the subarray with the largest sum, and return its sum.

//In this Algo, we ask shld I continue the current subarray? OR shld I start a new subarray from here?

//shld use kadane in following types of Qns :  
//max/min sum subarray
//max product subarray   ,  max circular subarray

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = 0;            //running sum of current subarray
        int maxSum = INT_MIN;          //stores best(max) sum found so far

        for (int i=0; i < nums.size(); i++){
            currentSum += nums[i];    //add running element to current sum
            maxSum = max(maxSum, currentSum);   //update maxSum if currentSum is better

            if (currentSum < 0){            //if running sum becomes negative
               currentSum = 0;              //reset it, start new subarray
            }
        }
        return maxSum;
    }
};