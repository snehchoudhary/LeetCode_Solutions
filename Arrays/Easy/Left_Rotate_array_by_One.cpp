#include<iostream>
#include<vector>
using namespace std;

//solution using extra space
class Solution {
    public:
  
    void RotateArrayByOne(vector<int>&nums){
        int n = nums.size();
        vector<int>ans(n);

        for(int index = 0; index < n; index++){
            int newIndex = (index - 1 + n)%n;
            ans[newIndex] = nums[index];
        }
        nums = ans;
    }
};

//solution without using extra space - most preferred in interviews
class Solution {
  public:

  void leftRotateByOne(vector<int>&nums){
    //store first element 
    int first = nums[0];

    for (int i = 1; i < nums.size(); i++){
        nums[i - 1] = nums[i];
    }
    nums[nums.size() - 1] = first;
  }
};