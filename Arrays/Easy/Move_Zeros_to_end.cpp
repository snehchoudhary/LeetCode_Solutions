#include<iostream>
#include<vector>
using namespace std;

// we need to move all zeros in an array at end but the catch is sequence of element should remain.

//thought of two approaches : rotate elements = 0 to right
//                          : two pointer approach and swap

//ROTATE 0 TO RIGHT
class Solution {
public:

void moveZerosToEnd(vector<int>&nums){

    int n = nums.size();

    for (int i = 0; i < n; i++){
        if(nums[i] == 0){
            int temp = nums[i];

            for (int j = i; j < n-1; j++){
                nums[j] = nums[j+1];
            }
            nums[n-1] = temp;

            //stay at same index bcoz new element arrived to index i after rotation
            i--;
            n--;
        }
    }
}
};

//T.C for above approach is O(n^2) because every element need to rotate in this case and S.C is O(1).

//Better to use TWO POINTER APPROACH
class Solution {
    public:

    void moveZerostoEnd (vector<int>&nums){
      int j = 0;
      for(int i = 0; i < nums.size(); i++){
        if(nums[i] != 0){
            swap(nums[i], nums[j]);
            j++;
        }
      }
    }
};

//T.C for this TWO POINTER APPROACH is O(n) bcoz traversal of complete array took place single time only and S.C is O(1)

//Above TWO POINTER : both pointers were on same side....wht if TWO POINTERS are on different sides of array

class Solution {
public:

void rotateZerosToEnd(vector<int>&nums){
    for(int i = 0; i < nums.size(); i++){
        for (int j = nums.size()-1; j> i; j--){
            if(nums[i] == 0 && nums[j]!=0){
                swap(nums[i], nums[j]);
            }
        }
    }
}
};

//the above solution gives wrong answer as it is not preserving the relative order of all elements in an array