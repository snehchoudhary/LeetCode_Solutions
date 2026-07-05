#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<climits>
using namespace std;

//brute force : TC O(n^3)
class Solution {
public:

    bool isUnique(string &s, int i, int j) {

        vector<int> freq(256, 0);

        for(int k = i; k <= j; k++) {

            if(freq[s[k]] > 0)
                return false;

            freq[s[k]]++;
        }

        return true;
    }

    int lengthOfLongestSubstring(string s) {

        int n = s.size();
        int maxLen = 0;

        for(int i = 0; i < n; i++) {

            for(int j = i; j < n; j++) {

                if(isUnique(s, i, j)) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};


//optimal approach :
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector <int> last(256, -1);   //to store last index of each char
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right++){
            if (last[s[right]] >= left){
                left = last[s[right]] + 1;  //move left after repeated char
            }
            last[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};