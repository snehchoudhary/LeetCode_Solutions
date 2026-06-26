#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:

    void solve(vector<int>& nums, int index, 
               vector<int>& current, 
               vector<vector<int>>& ans) {


        // Base case:
        // When we have considered all elements
        if(index == nums.size()) {

            // store current subset
            ans.push_back(current);

            return;
        }


        // Choice 1: Include current element

        current.push_back(nums[index]);

        solve(nums, index + 1, current, ans);



        // Backtracking:
        // remove element to try another choice

        current.pop_back();



        // Choice 2: Exclude current element

        solve(nums, index + 1, current, ans);
    }



    vector<vector<int>> subsets(vector<int>& nums) {


        vector<vector<int>> ans;   // stores all subsets


        vector<int> current;       // current subset being formed


        solve(nums, 0, current, ans);


        return ans;
    }
};