#include<iostream>
#include<vector>
using namespace std;


//Giving TLE: 
class Solution {
public:

    int firstOccurrence(vector<int>& nums, int target){
        int start = 0;
        int end = nums.size()-1;
        int ans = -1;

        while(start <= end){
            int mid = start + (end-start)/2;

            if(nums[mid] == target){
                ans = mid;          // store index
                end = mid - 1;      // move left to find first
            }
            else if(nums[mid] < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }

        return ans;
    }


    int lastOccurrence(vector<int>& nums, int target){
        int start = 0;
        int end = nums.size()-1;
        int ans = -1;

        while(start <= end){
            int mid = start + (end-start)/2;

            if(nums[mid] == target){
                ans = mid;          // store index
                start = mid + 1;    // move right to find last
            }
            else if(nums[mid] < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }

        return ans;
    }


    vector<int> searchRange(vector<int>& nums, int target) {

        int first = firstOccurrence(nums,target);
        int last = lastOccurrence(nums,target);

        return {first,last};
    }
};

//BETTER CODE:
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int start = 0, end = nums.size()-1;
        int first = -1, last = -1;

        // first occurrence
        while(start <= end){
            int mid = start + (end-start)/2;

            if(nums[mid] == target){
                first = mid;
                end = mid - 1;
            }
            else if(nums[mid] < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }


        start = 0;
        end = nums.size()-1;

        // last occurrence
        while(start <= end){
            int mid = start + (end-start)/2;

            if(nums[mid] == target){
                last = mid;
                start = mid + 1;
            }
            else if(nums[mid] < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }

        return {first,last};
    }
};