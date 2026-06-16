//Given an integer array nums of size n, sorted in ascending order with distinct values. The array has been right rotated an unknown number of times, between 0 and n-1 (including). Determine the number of rotations performed on the array.

//THOUGHT PROCESS: index of minimum element is the number of rotations

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findKRotation(vector<int> &nums)  {
        int left = 0, right = nums.size() - 1;

        while (left < right){
            int mid = (left + right)/2;

            if(nums[mid] < nums[right]){
                right = mid;
            }
             else{
                left = mid + 1;
             }
        }
        return left;
    }
};