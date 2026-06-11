//nums = [3, 1, -2, -5, 2, -4]
//output: [3, -2, 1, -5, 2, -4]

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos, neg;

        for (int x: nums){
            if (x > 0) pos.push_back(x);
            else neg.push_back(x);
        }
        vector<int>ans(nums.size());
        int i =0; int j =0; int k =0;

        while(i < pos.size()){
            ans[k++] = pos[i++];
            ans[k++] = neg[j++];
        }
        return ans;
    }
};