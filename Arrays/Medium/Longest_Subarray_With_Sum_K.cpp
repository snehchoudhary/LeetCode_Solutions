//nums = [10, 5, 2, 7, 1, 9] k= 15
//find longest subarray whose sum should be equal to 15
//APPROACH: SLIDING WINDOW

//BRUTE FORCE : O(N^2)

#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

class Solution {
public: 
 int longestSubarray(vector<int> &nums, int k){
        int maxLen = 0;
        for (int i =0; i < nums.size(); i++){
            int sum = 0;
            for(int j = i; j < nums.size(); j++){
                sum = sum + nums[j];

                if(sum == k){
                    maxLen = max(maxLen, j-i+1);
                }
            }
        }
        return maxLen;
    }
};


//OPTIMAL APPROACH : TWO POINTERS LEFT AND RIGHT
//CATCH : This 2 pointer approach will only give optimal solution in case of positive numbers....if -ve numbers allowed then use Prefix Sum + Hashmap

class Solution {
public:

int longestSubarray(vector<int>&nums, int k){
    int left = 0; int right =0; int sum = 0; int maxLen = 0;

    while(right < nums.size()){
        sum = sum + nums[right];

        while(sum > k){
          sum = sum - nums[left];
          left = left + 1;
        }
        if (sum == k){
            maxLen = max(maxLen, right - left + 1);
            right = right+1;
        }
    }
    return maxLen;
}
};

//OPTIMAL APPROACH : PREFIX SUM + HASHMAP
class Solution {
public:

int longestSubarray(vector<int>&nums, int k ){
    unordered_map<long long, int>mp;

    long long sum =0;
    int maxLen = 0;

    for (int i = 0; i < nums.size(); i++){
        sum = sum + nums[i];

        if(sum == k){
            maxLen = i + 1;
        }
        if (mp.find(sum - k) != mp.end()){
            maxLen = max(maxLen, i - mp[sum - k]);
        }
        if(mp.find(sum) == mp.end()){
            mp[sum] = i;
        }
    }
    return maxLen;
}
};