#include<iostream>
#include<vector>
using namespace std;

//BRUTE FORCE APPROACH:  TC : O(n^2)          SC: O(1)
 
//square elements
class Solution {
public:

vector<int>squareOfSortedArray(vector<int>&nums){

    //square elements
    for (int i = 0; i <nums.size(); i++){
        nums[i] = nums[i] * nums[i];
    }

    //sort array
    for(int i = 0; i < nums.size(); i++){
        for(int j = i + 1; j < nums.size(); j++){
            if(nums[j] < nums[i]){
                swap(nums[i], nums[j]);
            }
        }
    }
    return nums;
}
};

//OPTIMAL APPROACH : TWO POINTERS    TC: O(n)         SC : O(n)
class Solution {
public:

vector<int>squareOfSortedArray(vector<int>&nums)
{
    int n = nums.size();
    vector<int>result(n);

    int left = 0;
    int right = n - 1;
    int pos = n - 1;

    while (left <= right) {
        int leftSq = nums[left] * nums[left];
        int rightSq = nums[right] * nums[right];

        if (leftSq > rightSq){
            result[pos] = leftSq;
            left ++;
        }
         else{
            result[pos] = rightSq;
            right--;
         }
         pos--;
    }
    return result;
}};