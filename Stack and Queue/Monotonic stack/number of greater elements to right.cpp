#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {

        vector<int> ans;

        for (int idx : indices) {

            int count = 0;

            for (int j = idx + 1; j < arr.size(); j++) {
                if (arr[j] > arr[idx])
                    count++;
            }

            ans.push_back(count);
        }

        return ans;
    }
};