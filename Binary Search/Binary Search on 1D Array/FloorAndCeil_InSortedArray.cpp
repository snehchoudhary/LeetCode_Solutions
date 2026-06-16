//Given a sorted array nums and an integer x. Find the floor and ceil of x in nums. The floor of x is the largest element in the array which is smaller than or equal to x. The ceiling of x is the smallest element in the array greater than or equal to x. If no floor or ceil exists, output -1.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
     int start = 0;
     int end = nums.size() - 1;
     int floor = -1;
     int ceil = -1;

     while (start <= end){
        int mid = (start + end)/2;

        if(nums[mid] == x){
            floor = nums[mid];
            ceil = nums[mid];
            break;
        }
        else if(nums[mid] < x){
            floor = nums[mid];
            start = mid + 1;
        }
        else{
            ceil = nums[mid];
            end = mid -1;
        }
     }
     return {floor, ceil};
    }
};