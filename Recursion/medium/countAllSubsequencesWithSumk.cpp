#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:

    int countSubsequence(int index, int s, int sum, vector<int>& nums, int n){

        if(index == n){
            return (s == sum) ? 1 : 0;
        }

        // pick
        int left = countSubsequence(index + 1, s + nums[index], sum, nums, n);

        // not pick
        int right = countSubsequence(index + 1, s, sum, nums, n);

        return left + right;
    }


    int countSubsequenceWithTargetSum(vector<int>& nums, int k){

        return countSubsequence(0, 0, k, nums, nums.size());
    }
};