//You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
//Return the single element that appears only once.
//Your solution must run in O(log n) time and O(1) space.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
      int left = 0, right = nums.size() - 1;
      while (left < right) {
        int mid = (left + right) / 2;
        if (mid % 2 == 1) {
            mid--;
        }
        if (nums[mid] != nums[mid + 1]) {
            right = mid;
        } else {
            left = mid + 2;
        }
      }  
      return nums[left];
    }
};

//THOUGHT PROCESS : Before the single element:

//index:  0 1 2 3 4 5 6 7 8
//nums:   1 1 2 3 3 4 4 8 8

//Pairs start at even indices:

//(0,1) → 1
//(3,4) → 3
//(5,6) → 4
//(7,8) → 8

//But after the single element, the pairing pattern breaks.

//Before single:

//even index == odd index

//After single:

//even index != odd index


//If no special property → XOR is great
//If sorted → use binary search for the best complexity
//If you need frequency → HashMap


