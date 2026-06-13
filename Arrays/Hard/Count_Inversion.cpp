//Given an integer array nums. Return the number of inversions in the array.
//Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
//It indicates how close an array is to being sorted.
//A sorted array has an inversion count of 0.
//An array sorted in descending order has maximum inversion.

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    long long int numberOfInversions(vector<int> nums) {

        int n = nums.size();
        long long count = 0;

        for(int i = 0; i < n; i++){

            for(int j = i+1; j < n; j++){

                if(nums[i] > nums[j]){
                    count++;
                }

            }
        }

        return count;
    }
};

//above is the brute force approach, TC : O(n^2) bcoz of nested loops

//OPTIMIZED APPROACH : MERGE SORT TECHNIQUE

class Solution {
public:

    long long merge(vector<int>& nums, int low, int mid, int high){

        vector<int> temp;

        int left = low;
        int right = mid + 1;

        long long count = 0;


        while(left <= mid && right <= high){

            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                // inversion found
                count += (mid - left + 1);

                temp.push_back(nums[right]);
                right++;
            }
        }


        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }


        while(right <= high){
            temp.push_back(nums[right]);
            right++;
        }


        // put sorted values back
        for(int i = low; i <= high; i++){
            nums[i] = temp[i-low];
        }


        return count;
    }



    long long mergeSort(vector<int>& nums, int low, int high){

        long long count = 0;

        if(low >= high)
            return 0;


        int mid = low + (high-low)/2;


        count += mergeSort(nums, low, mid);

        count += mergeSort(nums, mid+1, high);


        count += merge(nums, low, mid, high);


        return count;
    }



    long long int numberOfInversions(vector<int> nums) {

        int n = nums.size();

        return mergeSort(nums, 0, n-1);

    }
};

//T.C: O(N LOG N)
//S.C: O(N)