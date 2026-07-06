#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxTotal = 0;
        for (int i =0; i < nums.size(); i++){
            if ( i > maxTotal)
              return false;

            maxTotal = max(maxTotal, i + nums[i]);
        }
        return true;
    }
};