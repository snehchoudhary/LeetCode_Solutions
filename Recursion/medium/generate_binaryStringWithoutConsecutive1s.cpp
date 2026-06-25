#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:

    void solve(int n, string current, vector<string>&ans){
        //base case
        if (current.length() == n){
            ans.push_back(current);
            return;
        }
        //choice 1: add 0
        solve(n, current + "0", ans);

        //choice 2: add 1 only if previous is not 1
        if(current.empty() || current.back() != '1'){
            solve(n, current + "1", ans);
        }
    }
    vector<string> generateBinaryStrings(int n) {
        // Your code goes here
         vector<string> ans;

        solve(n, "", ans);

        return ans;
    }
};
