//Given a sorted array of nums and an integer x, write a program to find the upper bound of x.
//The upper bound of x is defined as the smallest index i such that nums[i] > x.
//If no such index is found, return the size of the array.

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int upperBound(vector<int> &nums, int x){
        int start = 0;
        int end = nums.size() - 1;
        int mid = (start + end)/2;

        while(start <= end){
            if (nums[mid] > x){
                return mid;
                end = mid - 1;
            }
            
            else {
                start = mid + 1;
            }
            mid = (start + end)/2;
        }
        return nums.size();
    }
};