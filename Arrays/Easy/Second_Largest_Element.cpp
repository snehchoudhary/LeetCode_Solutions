#include<iostream>
#include<Vector>
using namespace std;

class Solution {
    public:

    int secondLargestElement(vector<int>&nums){
        int max = nums[0];
        int secMax = -1;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] > max){
                max = nums[i];
                secMax = max;
            }
            else if (nums[i] > secMax && nums[i] < max){
                secMax = nums[i];
            }
        }
        return secMax;
    }
};