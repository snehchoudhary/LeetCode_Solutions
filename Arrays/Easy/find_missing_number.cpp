#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++){
            sum = sum + nums[i];
        }
        int expected_sum = n * (n + 1) / 2;
        

        if (sum == expected_sum)
         return -1;

        else {
            return expected_sum - sum;
        }
    }
};