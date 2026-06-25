#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;


//BRUTE FORCE APPROACH:
// The simple way:

// ans = 1

// repeat n times:
//     ans *= x

// Example:

// 2^5

// ans = 1

// ans = 1*2 = 2
// ans = 2*2 = 4
// ans = 4*2 = 8
// ans = 8*2 = 16
// ans = 16*2 = 32

// Time:

// O(n)

// For:

// 2^31

// this is too slow.


//OPTIMAL APPROACH : BINARY EXPONENTIATION

// Instead of multiplying x again and again, reduce the exponent by half.

// Mathematical property:

// x^10

// can be written as:

// (x^2)^5

// Again:

// (x^2)^5  =  (x^2)^4 × x^2

// Again:

// (x^4)^2 ×  x^2

// So every time we square x and divide exponent by 2.

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;    //use long long to handle - 2^31 case

        //handling negative powers
        if (N < 0){
            x =1/x;
            N = -N;
        }

        //stores final ans
        double ans =1;
        while (N > 0){                     //keep reducing exponent

            //if current power is odd
            if (N % 2 == 1) ans *= x;     //multiply when bit is set
            x *= x;                      //square the base
            N /= 2;                     //halve the exponent
        
}
 return ans;
    }
};



// Why does this work?

// Because we are using the binary representation of exponent.

// Example:

// 10 in binary = 1010

// Meaning:

// 10=8+2

// So:

// 2^10  =  2^8 × 2^2

// Our algorithm finds exactly those powers.