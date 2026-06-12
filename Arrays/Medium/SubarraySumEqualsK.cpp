//Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

//BRUTE FORCE APPROACH : SLIDING WINDOW -->> GENERATE ALL SUBARRAYS AND CHECK EACH SUBARRAY WHETHERE IT'S SUM = K OR NOT

//TIME COMPLEXITY : O(N^2)
//SPACE COMPLEXITY : O(1)


#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:

int longestSubarray(vector<int>&nums, int k){
    int count = 0;

    for (int i = 0; i< nums.size(); i++){
        int sum = 0;
        for (int j = 0; j< nums.size(); j++){
            sum = sum + nums[i];

            if (sum == k){
                count++;
            }
        }
    }
    return count;
}
};

//BETTER APPROACH : PREFIX SUM + HASHMAP
class Solution {
public:

int longestSubarray(vector<int>&nums, int k){
    unordered_map<int, int>mp;

    mp[0] = 1;
    int prefixSum = 0;
    int count = 0;

    for (int i = 0; i < nums.size()-1; i++){
        prefixSum = prefixSum + nums[i];

        //check if (prefixSum - k) already exists
        if (mp.find(prefixSum - k) != mp.end()){
            count = count + mp[prefixSum - k];
        }
        //store prefixSum
        mp[prefixSum]++;
    }
    return count;
}
};