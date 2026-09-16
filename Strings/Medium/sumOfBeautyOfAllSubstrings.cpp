#include<iostream>
#include<limits.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {

            int freq[26] = {0};

            for (int j = i; j < n; j++) {

                // Add current character
                freq[s[j] - 'a']++;

                int maxFreq = 0;
                int minFreq = INT_MAX;

                // Find max and min non-zero frequency
                for (int k = 0; k < 26; k++) {

                    if (freq[k] > 0) {
                        maxFreq = max(maxFreq, freq[k]);
                        minFreq = min(minFreq, freq[k]);
                    }
                }

                // Add beauty of current substring
                ans += maxFreq - minFreq;
            }
        }

        return ans;
    }
};