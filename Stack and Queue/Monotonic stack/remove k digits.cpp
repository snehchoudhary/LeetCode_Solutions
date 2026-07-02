#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {

        stack<char> st;

        // Step 1: Build monotonic increasing stack
        for (char digit : num) {

            while (!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }

            st.push(digit);
        }

        // Step 2: If k still remains, remove from end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Step 3: Build result string
        string result = "";

        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        // Step 4: Reverse once
        reverse(result.begin(), result.end());

        // Step 5: Remove leading zeros
        int i = 0;

        while (i < result.size() && result[i] == '0') {
            i++;
        }

        result = result.substr(i);

        // Step 6: If empty return "0"
        if (result == "")
            return "0";

        return result;
    }
};