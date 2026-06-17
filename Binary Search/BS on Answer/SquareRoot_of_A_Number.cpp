//Given a positive integer n. Find and return its square root. If n is not a perfect square, then return the floor value of sqrt(n).

#include<iostream>
#include<Vector>
using namespace std;

class Solution {
public:
    int floorSqrt(int n)  {
      
        int left = 1;
        int right = n -1;
        int ans = 0;

        while (left <= right){
            long long mid = (right - left)/2;

            if(mid * mid <= n){
                ans = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return ans;
    }
};