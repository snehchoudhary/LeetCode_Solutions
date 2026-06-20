//Given an array of integers nums, calculate the pivot index of this array.

//The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

//If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

//Return the leftmost pivot index. If no such index exists, return -1.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    int prefixSumApproach(vector<int>nums){
      vector<int>leftSum(nums.size(), 0);
      vector<int>rightSum(nums.size(), 0);


      //calculate left sum array
      for(int i=1; i<nums.size(); ++i)
      leftSum[i] = leftSum[i-1] + nums[i-1];

      //calculate right sum array
      for(int i=nums.size()-2; i>=0; --i)
      rightSum[i] = rightSum[i+1] + nums[i+1];

      //check
      for(int i =0; i<nums.size(); ++i){
      if(leftSum[i] == rightSum[i]) return i;
    }
    return -1;
    }

    int pivotIndex(vector<int>& nums) {
        return prefixSumApproach(nums);
    }
};