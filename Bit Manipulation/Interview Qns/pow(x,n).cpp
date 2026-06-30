// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Implement:

// pow(x,n)=x
// n

// Example:

// x = 2, n = 10

// 2^10 = 1024

// We need to handle:

// Positive exponent
// Negative exponent
// Large n

// Brute Force Approach — O(n)
// Multiply x n times.

class Solution
{
public:
    double myPow(double x, int n)
    {

        double ans = 1;

        int power = abs(n);

        for (int i = 0; i < power; i++)
        {
            ans *= x;
        }

        if (n < 0)
            ans = 1 / ans;

        return ans;
    }
};

// Better Approach — Recursive Binary Exponentiation O(log n)
// Instead of multiplying x n times:

// x^10

// = x^5 * x^5

// x^5

// = x^2 * x^2 * x

// We divide exponent by 2 every time.

class Solution
{
public:

    double power(double x, long long n)
    {

        if(n == 0)
            return 1;


        double half = power(x, n / 2);


        if(n % 2 == 0)
            return half * half;

        else
            return half * half * x;
    }



    double myPow(double x, int n)
    {

        long long exponent = n;


        if(exponent < 0)
        {

            exponent = -exponent;

            return 1 / power(x, exponent);
        }


        return power(x, exponent);
    }
};
// Optimal Approach — Iterative Binary Exponentiation O(log n)
// Use binary representation of n.

class Solution
{
public:
    double myPow2(double x, int n)
    {

        long long power = n;

        if (power < 0)
        {
            x = 1 / x;
            power = -power;
        }

        double ans = 1;

        while (power > 0)
        {

            if (power % 2 == 1)
            {
                ans = ans * x;
            }

            x = x * x;

            power = power / 2;
        }

        return ans;
    }
};
