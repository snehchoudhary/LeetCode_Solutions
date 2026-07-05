#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

//brute force : TC : O(n^2)

class Solution {
public:

    int atMostK(vector<int>&nums, int k ){
        int n = nums.size();
        int count = 0;

        for (int i = 0 ; i < n; i++){
            unordered_map<int, int>mp;

            for (int j = i; j < n; j++){
                mp[nums[j]]++ ; 

                if (mp.size() > k)
                break;

                count++;
            }
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};



//optimal approach : sliding window : O(n)

class Solution {
public:


    int atMostK(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        int left = 0;
        int count = 0;

        for(int right = 0; right < nums.size(); right++) {

            mp[nums[right]]++;

            while(mp.size() > k) {
                mp[nums[left]]--;

                if(mp[nums[left]] == 0)
                    mp.erase(nums[left]);

                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};