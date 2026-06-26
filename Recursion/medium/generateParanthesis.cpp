#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:

    void solve(int n, string current, int open, int close, vector<string>& ans) {
        //base case
        if(current.length() == 2*n){
            ans.push_back(current);
            return ;
        }

        if (open < n){
            solve(n, current + "(", open + 1, close, ans);
        }
        if (close < open){
            solve(n, current + ")", open, close + 1, ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;

        solve(n, "", 0, 0 , ans);
        return ans;
    }
};