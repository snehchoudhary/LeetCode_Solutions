//You are given an integer array arr of size n which contains both positive and negative integers. Your task is to find the length of the longest contiguous subarray with sum equal to 0.
//Return the length of such a subarray. If no such subarray exists, return 0.

//APPROACH : PREFIX SUM + HASHMAP
//WHY NOT SLIDING WINDOW? Bcoz negative numbers are also present, sliding window can only be reliable only in the case of positive elements only

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // Your code goes here

       unordered_map<int, int>mp;
       int prefixSum = 0;
       int maxLength = 0;

       for(int i = 0; i < arr.size(); i++){
        prefixSum = prefixSum +arr[i];

        //if prefix sum itself is a zero
        if(prefixSum == 0){
            maxLength =  i + 1;
        }

        //if this sum was seen before
        if(mp.find(prefixSum) != mp.end()){
            int length = i - mp[prefixSum];
            maxLength = max(maxLength, length);
        }
        else{
            //store first ocurrence only
            mp[prefixSum] = i;
        }

       }
       return maxLength;
    }
};