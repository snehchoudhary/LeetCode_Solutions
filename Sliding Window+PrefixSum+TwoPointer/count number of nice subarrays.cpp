#include<iostream>
#include<vector>
using namespace std;

//BRUTE FORCE APPROACH

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count = 0;

        for (int i = 0 ; i < nums.size() ; i++){
            int oddCount = 0;

        for (int j = i; j < nums.size(); j++){
            if (nums[j] % 2 != 0)
               oddCount ++;

            if (oddCount == k)
               count++;

                   }
                
        }
        return count;
    }
};