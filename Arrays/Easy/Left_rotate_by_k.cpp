#include<iostream>
#include<vector>
using namespace std;

//Formula to rotate by k places to left --- >>  (index - k + n ) % n
//for right rotation by k places --->> (index + k) % n

class Solution {
    public:
    void rotateArray(vector<int>&nums, int k) {
     
        int n = nums.size();
        vector<int>ans(n);
        k = k % n;

        for (int index = 0; index < n; index++){
            int newIndex = (index - k + n) % n;
            ans[newIndex] = nums[index];
        }
        nums = ans;
    }
};
