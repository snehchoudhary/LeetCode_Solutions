//Given an array of integers nums and an integer k, return the total number of subarrays whose XOR equals to k.

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
      int count = 0;

      for(int i = 0; i < nums.size(); i++){
        int ans = 0;

        for(int j = i; j < nums.size(); j++){
            ans = ans^nums[j];

            if(ans == k)
             count++;
        }
      }  
      return count;
    }
};