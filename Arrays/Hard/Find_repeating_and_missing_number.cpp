//Given an integer array nums of size n containing values from [1, n] and each value appears exactly once in the array, except for A, which appears twice and B which is missing.
//Return the values A and B, as an array of size 2, where A appears in the 0-th index and B in the 1st index.

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:

vector<int> findMissingRepeatingNumbers(vector<int> nums){
    int n = nums.size();

    unordered_map<int, int>mp;

    int A = -1; int B = -1;

    //find repeating number
    for (int i = 0; i < n; i++){
        mp[nums[i]]++;

        if(mp[nums[i]] == 2)
         A = nums[i];
    }

    //find missing number
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++){
         if(nums[i] != i+1){
                B = i+1;
                break;
            }
    }
    //edge case: missing n
    if ( B == -1)
    B = n;

    return {A, B};
   
}

};

//T.C : O(N)
//S.C : O(1)
//CATCH : IF IT IS NOT ALLOWED TO MODIFY THE ORIGINGAL ARRAY.....here we are sorting the array and changing the original array

//SOLUTION : vector<int> temp = nums;
//sort(temp.begin(), temp.end());

class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int>& nums) {

        int n = nums.size();

        int A = -1;
        int B = -1;

        // Step 1: Find repeating number
        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++){

            mp[nums[i]]++;

            if(mp[nums[i]] == 2){
                A = nums[i];
            }
        }


        // Step 2: Make copy because original cannot be modified
        vector<int> temp = nums;

        sort(temp.begin(), temp.end());


        // Step 3: Find missing number
        for(int i = 0; i < n; i++){

            if(temp[i] != i+1){

                B = i+1;
                break;
            }
        }


        // If missing number is n
        if(B == -1)
            B = n;


        return {A,B};
    }
};