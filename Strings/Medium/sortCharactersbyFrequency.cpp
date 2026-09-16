#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {

        // Step 1: Count frequency
        unordered_map<char, int> mp;

        for (char ch : s) {
            mp[ch]++;
        }

        // Step 2: Store character-frequency pairs
        vector<pair<char, int>> freq;

        for (auto it : mp) {
            freq.push_back({it.first, it.second});
        }

        // Step 3: Sort by decreasing frequency
        sort(freq.begin(), freq.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        // Step 4: Build answer
        string ans = "";

        for (auto it : freq) {
            for (int i = 0; i < it.second; i++) {
                ans += it.first;
            }
        }

        return ans;
    }
};