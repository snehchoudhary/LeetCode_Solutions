#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    void solve(int index, int k, int n,
               vector<int>& ds,
               vector<vector<int>>& ans){

        if(index == 10){

            if(ds.size() == k && n == 0){
                ans.push_back(ds);
            }

            return;
        }


        // pick
        ds.push_back(index);

        solve(index+1, k, n-index, ds, ans);

        ds.pop_back();


        // not pick
        solve(index+1, k, n, ds, ans);
    }


    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> ans;
        vector<int> ds;

        solve(1, k, n, ds, ans);

        return ans;
    }
};