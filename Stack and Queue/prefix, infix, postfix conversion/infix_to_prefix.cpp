#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
public:
    int priority(char ch) {
        if (ch == '^') return 3;
        if (ch == '*' || ch == '/') return 2;
        if (ch == '+' || ch == '-') return 1;
        return -1;
    }

    string infixToPrefix(string s) {

        // Step 1: Reverse the infix expression
        reverse(s.begin(), s.end());

        // Step 2: Swap '(' and ')'
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                s[i] = ')';
            else if (s[i] == ')')
                s[i] = '(';
        }

        stack<char> st;
        string ans = "";

        // Step 3: Convert reversed infix to postfix
        for (int i = 0; i < s.size(); i++) {

            if ((s[i] >= 'A' && s[i] <= 'Z') ||
                (s[i] >= 'a' && s[i] <= 'z') ||
                (s[i] >= '0' && s[i] <= '9')) {

                ans += s[i];
            }

            else if (s[i] == '(') {
                st.push(s[i]);
            }

            else if (s[i] == ')') {

                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }

                st.pop(); // remove '('
            }

            else {

                while (!st.empty() &&
                       st.top() != '(' &&
                       priority(s[i]) < priority(st.top())) {

                    ans += st.top();
                    st.pop();
                }

                st.push(s[i]);
            }
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        // Step 4: Reverse postfix to get prefix
        reverse(ans.begin(), ans.end());

        return ans;
    }
};