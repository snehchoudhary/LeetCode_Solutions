#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        int i = 0;
        int n = intervals.size();

        //sort by end time
         sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b){
                 return a[1] < b[1];
             });

        for (int j = i+1; j < n; j++){
            if (intervals[j][0] < intervals[i][1]){
                count++;
                
            }
        else {
            i = j;
        }
        }
        return count;
    }
};