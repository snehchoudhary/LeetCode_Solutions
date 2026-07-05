#include<iostream>
#include<vector>
using namespace std;

//BRUTE FORCE APPROACH

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++){
            int sum = 0;
        
        for (int j = i; j < n; j++){
            sum += nums[j];

            if (sum == goal)
             count ++;
        }

        }
        return count;
    }
};


//OPTIMISED APPROACH

class Solution {
public:

    int countAtMost(vector<int>&nums, int goal){
        if (goal < 0) return 0;

        int left = 0;
        int sum = 0;
        int count = 0;

        for (int right = 0; right < nums.size(); right++){
            sum += nums[right];

            while (sum > goal){
                sum -= nums[left];
                left++;
            }
            count = count + (right - left + 1);
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countAtMost(nums, goal) - countAtMost(nums, goal - 1);
    }
};