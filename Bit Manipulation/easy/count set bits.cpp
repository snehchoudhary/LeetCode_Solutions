#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int countSetBits(int n) {
        // Your code goes here
        int count = 0;

        while (n > 1) {
            count += (n & 1);
            n = n >> 1;
        }
        if (n == 1){
            count += 1;
        }
        return count;
    }
};