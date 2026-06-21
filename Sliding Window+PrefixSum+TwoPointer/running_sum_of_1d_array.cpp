#include<iostream>
#include<vector>
using namespace std;

//prefix sum formula : 
//runningSum[i] = runningSum[i-1] + nums[i]


//TC : O(n)             SC : O(n)
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>result(n);

        result[0] = nums[0];

        for (int i =1; i < n; i++){
            //prefix formula
            result[i] = result[i-1] + nums[i];
        }
        return result;
    }
};


//TC : O(n)             SC : O(1)
class Solution {
public:

// space optimised in this code than the prev one

    vector<int> runningSum(vector<int>& nums) {
        for (int i =1; i < nums.size(); i++){
            nums[i] = nums[i] + nums[i-1];
        }
        return nums;
    }
};