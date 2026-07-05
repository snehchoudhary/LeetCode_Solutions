#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<climits>
using namespace std;

//brute : O(n^3)

//  Idea

// Try every substring of s1 and check:

// Is s2 a subsequence of it?

class Solution {
public:

    bool isSubsequence(string &sub, string &s2) {
        int j = 0;

        for(char c : sub) {
            if(c == s2[j]) {
                j++;
            }
            if(j == s2.size())
                return true;
        }

        return false;
    }

    string minWindow(string s1, string s2) {

        int n = s1.size();
        string ans = "";
        int minLen = INT_MAX;

        for(int i = 0; i < n; i++) {

            string sub = "";

            for(int j = i; j < n; j++) {

                sub += s1[j];

                if(isSubsequence(sub, s2)) {

                    if(j - i + 1 < minLen) {
                        minLen = j - i + 1;
                        ans = sub;
                    }
                }
            }
        }

        return ans;
    }
};


//better approach :(Two Pointers per start) O(n²)
//Idea

// Instead of checking every substring explicitly:

// Fix start i
// Try to find subsequence s2 starting from i

class Solution {
public:

    string minWindow(string s1, string s2) {

        int n = s1.size();
        string ans = "";
        int minLen = INT_MAX;

        for(int i = 0; i < n; i++) {

            int j = 0;
            int start = i;

            // forward match s2
            while(start < n && j < s2.size()) {
                if(s1[start] == s2[j])
                    j++;
                start++;
            }

            if(j == s2.size()) {

                // backward shrink
                int end = start - 1;
                j = s2.size() - 1;

                while(j >= 0) {
                    if(s1[end] == s2[j])
                        j--;
                    end--;
                }

                end++; // correct position

                if(start - end < minLen) {
                    minLen = start - end;
                    ans = s1.substr(end, minLen);
                }
            }
        }

        return ans;
    }
};

//OPTIMAL APPROACH (DP + Backtracking / Sliding Window)
//Key Insight

// We compute:

// For every index in s1, find best window starting there

// But efficiently using DP.

// DP Idea

// Define:

// dp[i][j] = starting index in s1 where s2[0..j] matches ending at i

// But better known optimized solution:

// 👉 Expand + Backtrack approach (most used in interviews)

// Optimal Algorithm (O(n × m))
// Step 1: Forward scan → find match
// Step 2: Backward scan → minimize window
// Step 3: Repeat

class Solution {
public:
    string minWindow(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();

        int minLen = INT_MAX;
        string ans = "";

        int i = 0;

        while(i < n) {

            int j = 0;

            // forward match
            while(i < n) {
                if(s1[i] == s2[j]) j++;

                if(j == m) break;
                i++;
            }

            if(j != m) break;

            int end = i;

            // backward shrink
            j = m - 1;

            while(i >= 0) {
                if(s1[i] == s2[j]) j--;

                if(j < 0) break;
                i--;
            }

            i++; // start index

            if(end - i + 1 < minLen) {
                minLen = end - i + 1;
                ans = s1.substr(i, minLen);
            }

            i = i + 1;
        }

        return ans;
    }
};