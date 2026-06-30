#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

//BRUTE FORCE APPROACH : O(n * x)

class Solution {
public:

    vector<int> primeFactor(int n) {

        vector<int> factors;

        for(int i = 2; i <= n; i++) {

            while(n % i == 0) {
                factors.push_back(i);
                n = n / i;
            }
        }

        return factors;
    }


    vector<vector<int>> primeFactorisation(vector<int>& queries) {

        vector<vector<int>> ans;

        for(int num : queries) {
            ans.push_back(primeFactor(num));
        }

        return ans;
    }
};

//BETTER OPTIMAL : O(n * √x)

class Solution {
public:

    vector<int> primeFactor(int n) {

        vector<int> factors;


        for(int i = 2; i*i <= n; i++) {

            while(n % i == 0) {

                factors.push_back(i);
                n = n / i;

            }
        }


        // remaining prime number
        if(n > 1)
            factors.push_back(n);


        return factors;
    }


    vector<vector<int>> primeFactorisation(vector<int>& queries) {

        vector<vector<int>> ans;


        for(int num : queries) {

            ans.push_back(primeFactor(num));

        }


        return ans;
    }
};

//OPTIMAL APPROACH : Using Sieve (Smallest Prime Factor)

class Solution {
public:

    vector<vector<int>> primeFactorisation(vector<int>& queries) {


        int maxi = *max_element(queries.begin(), queries.end());


        vector<int> spf(maxi + 1);


        // initialize
        for(int i = 0; i <= maxi; i++)
            spf[i] = i;



        // sieve
        for(int i = 2; i*i <= maxi; i++) {

            if(spf[i] == i) {

                for(int j = i*i; j <= maxi; j += i) {

                    if(spf[j] == j)
                        spf[j] = i;
                }
            }
        }



        vector<vector<int>> ans;



        for(int num : queries) {

            vector<int> factors;


            while(num != 1) {

                factors.push_back(spf[num]);

                num = num / spf[num];

            }


            ans.push_back(factors);
        }


        return ans;
    }
};
