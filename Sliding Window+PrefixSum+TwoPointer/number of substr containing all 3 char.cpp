#include<iostream>
#include<vector>
using namespace std;

//Brute force
//TC : O(N^3)
//SC : O(N)


class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int ans =0 ;

        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++) {
                 
                 bool hasA = false;
                 bool hasB = false;
                 bool hasC = false;

                 //check substr s[i.....j]
                 for (int k = i; k <= j; k++){
                    if (s[k] == 'a')
                      hasA = true;

                    else if (s[k] == 'b')
                      hasB = true;

                    else
                       hasC = true;
                 }
                 if (hasA && hasB && hasC)
                     ans++;
            }
        }
        return ans;
    }
};

//better brute force 
//TC : O(N^2)
//SC : O(1)

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int ans = 0;

        for (int i = 0; i < n; i++){
            int freq[3] = {0};

        for (int j = i; j < n; j++){
            freq[s[j] - 'a'] ++;

            //the above line of code is similar to :
            //if(s[j]=='a')
           //     freq[0]++;

          // else if(s[j]=='b')
             //     freq[1]++;

            // else
           //     freq[2]++;

           if (freq[0] > 0 && freq[1] > 0 && freq[2] > 0)
             ans++;
        }
        }
        return ans;
    }};


    //optimal approach : sliding window
//TC : O(n)

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length ();
        int freq[3] = {0};
        int left = 0;
        int ans = 0;

        for (int right = 0 ; right < n; right++){
            freq[s[right] - 'a'] ++;

            while(freq[0] > 0 &&
                  freq[1] > 0 &&
                  freq[2] > 0
                 ) {
                    ans += n - right;

                    freq[s[left] - 'a'] --;
                    left++;
                 }
        }
        return ans;
    }
};

//why ans += n - right ??
// Suppose

// Window = abc

// and

// right = 2

// Since

// abc

// already has all characters,

// adding more characters can never remove them.

// Therefore

// abc
// abca
// abcab
// abcabc

// are ALL valid.

// Instead of counting individually,

// we directly do

// n-right