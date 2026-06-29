#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool checkIthBit(int n, int i) {
        // Your code goes here

        if ((n & (1 << i)) != 0) return true;

        else {
            return false;
        }
    }
};