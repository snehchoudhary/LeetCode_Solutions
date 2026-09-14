#include<iostream>
#include<vector>

using namespace std;

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