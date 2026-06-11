// we need to find 1 unique element from the elements which are twice only single unique elelment is present in an array

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

int SingleNumber(vector<int>&nums){
    int ans = 0;
    for (int i = 0; i < nums.size(); i++){
        ans = ans^nums[i];
    }
    return ans;
}
};