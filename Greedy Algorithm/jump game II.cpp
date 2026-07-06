#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

// recursion approach:

class Solution {
public:
    int solve(int idx, vector<int>& nums) {

        int n = nums.size();

        // Reached the last index
        if (idx >= n - 1)
            return 0;

        int ans = INT_MAX;

        // Try every possible jump
        for (int jump = 1; jump <= nums[idx]; jump++) {

            if (idx + jump < n) {
                int res = solve(idx + jump, nums);

                if (res != INT_MAX)
                    ans = min(ans, 1 + res);
            }
        }

        return ans;
    }

    int jump(vector<int>& nums) {
        return solve(0, nums);
    }
};


//optimal : DP