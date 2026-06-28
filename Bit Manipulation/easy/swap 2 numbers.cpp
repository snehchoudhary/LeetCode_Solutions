#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
    void swap(int &a, int &b) {
        // Your code goes here

        a = a^b;
        b = a ^ b;
        a = a^ b;
    }
};


//refer bit manipulation notes for understanding background concept