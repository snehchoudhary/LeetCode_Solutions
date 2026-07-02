#include<iostream>
#include<vector>
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

    string infixToPostfix(string s) {

        stack<char> st;
        string ans = "";

        int n = s.size();

        for (int i = 0; i < n; i++) {

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

                st.pop();   // remove '('
            }

            else {

                while (!st.empty() &&
                       st.top() != '(' &&
                       priority(s[i]) <= priority(st.top())) {

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

        return ans;
    }
};