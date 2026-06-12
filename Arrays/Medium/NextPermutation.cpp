//we need to find next lexicographical order of given element. means as the words are arranged in dictionary e.g. [1 2 3 ] next order [1 3 2] as 1 <=1 ; 2 < 3

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

void nextPermutation(vector<int>& nums){
    int n = nums.size();     //e.g. [1 2 7 4 3 1] n = 6
    int i = n -2;            // i = n - 2 = 4.....i[4] = 3


    //FIND BREAKING POINT
    while(i >= 0 && nums[i] >= nums[i + 1]){        //nums[4] > nums[5] = 3 > 1   --->>> True
        i--;    //nums[3] > nums[4] = 4 > 3  --->>> True
                //nums[2] > nums[3] = 7 > 4  --->>> True
                //nums[1] > nums[2] = 2 > 7  --->>> False (BREAKING POINT)                                    
    }

   //FIND ELEMENT JUST GREATER THAN NUMS[I]
   int j = n -1;

   while(nums[j] <= nums[i]){       //nums[5] < nums[1]   = 1 < 2   --->>> True
    j--;                            //nums[4] < nums[1]   =  3 < 2  --->>> False
   }
  swap(nums[i], nums[j]);          //Array becomes : [1 3 7 4 2 1]

  //REVERSE ELEMENTS AFTER I
  reverse(nums.begin()+i+1, nums.end()) ;  //since i = 1  ;  Reverse [7 4 2 1]  ---> [1 2 4 7]
                                          //FINAL OUTPUT : [1 3 1 2 4 7]
                                           }
};