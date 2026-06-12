//Given an integer array nums, return a list of all the leaders in the array.
// A leader in an array is an element whose value is strictly greater than all elements to its right in the given array. The rightmost element is always a leader. The elements in the leader array must appear in the order they appear in the nums array.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
      vector<int>result;

      int maxRight = nums.back();
      result.push_back(maxRight);

      for (int i = nums.size()-2; i >= 0; i--){
        if (nums[i] > maxRight){
            result.push_back(nums[i]);
            maxRight = nums[i];
        }
      }
      reverse(result.begin(), result.end());
      return result;
    }
};

//why we are not using 2 pointers??? bcoz 2 pointers only checks for next greater element but we want rightmost to be greatest of all elements in it's right.
// so , we assumed rightmost element as the greatestand then comparing it with pointer i.