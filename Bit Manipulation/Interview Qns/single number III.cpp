//Given an array nums of length n, every integer in the array appears twice except for two integers. Identify and return the two integers that appear only once in the array. Return the two numbers in ascending order.
// For example, if nums = [1, 2, 1, 3, 5, 2], the correct answer is [3, 5], not [5, 3].

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

//BRUTE FORCE APPROACH : O(N^2) COUNT FREQUENCY

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {

            int count = 0;

            for(int j = 0; j < nums.size(); j++) {
                if(nums[i] == nums[j])
                    count++;
            }

            if(count == 1)
                ans.push_back(nums[i]);
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};

//BETTER SOLUTION : O(N)  USING HASHMAP

// Store frequency of every number.

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        unordered_map<int,int> mp;
        vector<int> ans;

        for(int x : nums) {
            mp[x]++;
        }


        for(auto it : mp) {

            if(it.second == 1)
                ans.push_back(it.first);
        }


        sort(ans.begin(), ans.end());

        return ans;
    }
};

//OPTIMAL APPROACH : XOR O(N), O(1)

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        int xorAll = 0;

        // XOR all numbers
        for(int x : nums) {
            xorAll ^= x;
        }


        // rightmost set bit
        int bit = xorAll & (-xorAll);


        int a = 0;
        int b = 0;


        // divide into two groups
        for(int x : nums) {

            if(x & bit)
                a ^= x;

            else
                b ^= x;
        }


        vector<int> ans = {a,b};

        sort(ans.begin(), ans.end());

        return ans;
    }
};