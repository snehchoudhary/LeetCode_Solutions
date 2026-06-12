//Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
//Notice that the solution set must not contain duplicate triplets.

//TWO SUM + SORTING PROBLEM

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:

vector<vector<int>> threeSum(vector<int>&nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>>ans;

    int n = nums.size();

    for (int i =0; i < n; i++){
        if(i > 0 && nums[i]==nums[i-1]) continue;                //skip duplicate i

        int l = i+1, r = n-1;

        while (l < r){
            int sum = nums[i] + nums[l] + nums[r];

            if(sum == 0){
                ans.push_back({nums[i], nums[l], nums[r]});

                //skip duplicates for l
                while( l < r && nums[l] == nums[l+1]) l++;

                //skip duplicates for r
                while(l < r && nums[r] == nums[r-1]) r--;

                l++;
                r--;
            }
            else if(sum < 0){
                l++;
            }
            else{
                r--;
            }

        }
    }
    return ans;
}
};