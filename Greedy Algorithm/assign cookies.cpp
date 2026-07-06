#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i = 0, j = 0;
        int n = g.size(), m = s.size();
        
        while (i < n && j < m) {
            if (s[j] >= g[i]) {
                // cookie satisfies the child
                i++;
                j++;
            } else {
                // cookie too small → try next bigger cookie
                j++;
            }
        }
        
        return i;  // number of satisfied children
    }
};