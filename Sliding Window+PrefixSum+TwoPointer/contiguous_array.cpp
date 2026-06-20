#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


//BRUTE FORCE APPROACH       TC : O(N^2)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxlen =0;
        int n = nums.size();

        for (int i = 0; i < n; i++){
            int zeroCount = 0;
            int oneCount = 0;

            for ( int j = i; j < n; j++){
                if (nums[j]==0){
                    zeroCount++;
                }
                else {
                    oneCount++;
                }
                if (zeroCount == oneCount){
                    maxlen = max (maxlen, j-i+1);
                }
            }
        }
        return maxlen;
    }
};


//OPTIMAL APPROACH : PREFIX SUM + HASHMAP     TC : O(N)
//optimal approach - prefixSum + hashmap

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;

        mp[0] = -1;

        int prefixSum = 0;
        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            //convert 0 -> -1
            if (nums[i] == 0) {
               prefixSum += -1;
            }
            else {
                prefixSum += 1;
            }

            //if prefixSum seen before ?
            if (mp.find(prefixSum) != mp.end()) {
                int length = i - mp[prefixSum];
                maxLen = max(maxLen, length);
            }
            else {
                //store the first occurrence
                mp[prefixSum] = i;
            }
        }
        return maxLen;
    }
};