//Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
//You must write an algorithm with O(log n) runtime complexity.


//SOLUTION:
//This question is basically Lower Bound.

//You need to find the first index where nums[i] >= target.

//Why?
//If target exists → that index is returned
//If target doesn't exist → that position is where target should be inserted

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int ans = nums.size();
       

        while(start <= end){
             int mid = (start + end)/2;

            if(nums[mid] >= target){
                ans = mid;
                end = mid -1;
            }
            else {
                start = mid + 1;
            }
            mid = (start + end)/2;
        }
        return ans;
    }
};