#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {

        //edge case

         return n > 0 && (n & (n - 1)) == 0;
         
        if ((n & (n - 1)) == 0) {
            return true;
        }
        else {
            return false;
        }
    }
};