//Given a sorted array of nums and an integer x, write a program to find the lower bound of x.
//The lower bound algorithm finds the first and smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.
//If no such index is found, return the size of the array.

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int lowerBound(vector<int> &nums, int x){
        int start = 0;
        int end = nums.size() - 1;
        int mid = (start + end)/2;

        while(start <= end){
            if(nums[mid] >= x){
                return mid;
            }
            else if (x > nums[mid]){
                start = mid + 1;
            }
            else if (x < nums[mid]){
                end = mid -1;
            }
            mid = (start + end)/2;
        }
        return nums.size();

    }
};