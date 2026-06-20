#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n = nums.size();
    //     int maxLen = 0;

    //     for (int i = 0; i < n; i++){
    //         int zeroCount = 0;

    //         for (int j = i; j < n; j++){
    //             if (nums[j] == 0){
    //                 zeroCount++;
    //             }
    //             if (zeroCount <= k){
    //                 maxLen = max(maxLen, j-i+1);
    //             }
    //             else {
    //                 break;
    //             }
    //         }
    //     }
    //     return maxLen;


    //BETTER APPROACH: SLIDING WINDOW

    int left = 0;
    int zeroCount = 0;
    int maxLen = 0;

    for (int right = 0; right < n; right++){

        //expand window
        if (nums[right] == 0)
         zeroCount++;

         //shrink window if invalid
         while (zeroCount > k) {
            if (nums[left] == 0)
            zeroCount--;

            left++;
         }
         //update maxlen
         maxLen = max(maxLen, right-left+1);
    }
    return maxLen;
     }
};