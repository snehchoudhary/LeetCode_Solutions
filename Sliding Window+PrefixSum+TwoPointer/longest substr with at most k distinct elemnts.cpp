#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

//brute force  : O(n^2)
// Idea

// Try every starting point.

// Expand until more than k distinct characters.

class Solution {
public:
    int longestSubstring(string s, int k) {

        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {

            unordered_map<char,int> mp;

            for(int j = i; j < n; j++) {

                mp[s[j]]++;

                if(mp.size() > k)
                    break;

                ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};

//optimal approach : sliding window : O(n)

// 1. Expand right

// Add character to map.

// 2. If invalid (map size > k)

// Remove from left until valid again.

// 3. Update answer

class Solution {
public:
    int longestSubstring(string s, int k) {

        unordered_map<char,int> mp;

        int left = 0;
        int ans = 0;

        for(int right = 0; right < s.size(); right++) {

            mp[s[right]]++;

            while(mp.size() > k) {

                mp[s[left]]--;

                if(mp[s[left]] == 0)
                    mp.erase(s[left]);

                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};