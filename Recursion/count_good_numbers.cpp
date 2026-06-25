#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

class Solution {
public:

    long long MOD = 1e9 + 7;

    long long power(long long x, long long n) {
        long long ans = 1;

        while(n > 0) {

            // if current bit is 1
            if(n % 2 == 1) {
                ans = (ans * x) % MOD;
            }

            // square the base
            x = (x * x) % MOD;

            // divide exponent by 2
            n /= 2;
        }

        return ans;
    }


    int countGoodNumbers(long long n) {

        long long evenPositions = (n + 1) / 2;
        long long oddPositions = n / 2;

        long long ans = power(5, evenPositions);

        ans = (ans * power(4, oddPositions)) % MOD;

        return ans;
    }
};