#include<iostream>
#include<vector>
using namespace std;


// using two pointers i and j

class Solution {
    public:

    bool checkIftheArrayIsSorted(vector<int>&nums){

    int i =0;
    int j = 1;

    while (j < nums.size() ){
        if (nums[i] > nums[j]){
            return false;
        }
        i++;
        j++;
    }
    return true;
    }
};

// using single pointer j
class Solution {
    public:

    bool checkifArraySorted(vector<int>&nums){
        for (int j =1; j < nums.size(); j++){
            if(nums[j] < nums[j - 1]){
                return false;
            }
        }
        return true;
    }
};