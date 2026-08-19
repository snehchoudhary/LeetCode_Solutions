#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> countFrequencies(vector<int>& nums) {
    unordered_map<int, int> mpp;

    // Count frequency
    for (int num : nums) {
        mpp[num]++;
    }

    // Store element and frequency
    vector<vector<int>> ans;

    for (auto it : mpp) {
        ans.push_back({it.first, it.second});
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 2, 1, 3};

    vector<vector<int>> ans = countFrequencies(nums);

    for (auto pair : ans) {
        cout << "[" << pair[0] << "," << pair[1] << "] ";
    }

    return 0;
}