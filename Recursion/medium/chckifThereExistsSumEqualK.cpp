#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution{
    public:

    bool any1Subsquence(int index, vector<int>&ds, int s, int sum, vector<int>&nums, int n) {
    if (index == n){

        //condition satisfied
        if (s == sum) {
            for (auto it : ds) cout << it << " ";
            cout << endl;
            return true;
        }
        //condition not satisfied
        else return false;
    }
    ds.push_back(nums[index]);
    s += nums[index];

    if(any1Subsquence(index+1, ds, s, sum, nums, n) == true){
        return true;
    }

    s-= nums[index];
    ds.pop_back();

    //not pick
    if(any1Subsquence(index + 1, ds, s, sum, nums, n) == true)  return true; 

    return false;
}

    bool checkSubsequenceSum(vector<int>& nums, int k) {
         //your code goes here
         vector<int>ds;
         return any1Subsquence(0, ds, 0, k, nums, nums.size());
    }
};