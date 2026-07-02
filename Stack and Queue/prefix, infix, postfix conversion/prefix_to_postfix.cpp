#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
public:
    string prefixToPostfix(const string& s) {
        
        stack<string> st;
        
        for (int i = s.size() - 1; i >= 0; i--) {
            
            char ch = s[i];
            
            // Operand
            if ((ch >= 'A' && ch <= 'Z') ||
                (ch >= 'a' && ch <= 'z') ||
                (ch >= '0' && ch <= '9')) {
                
                st.push(string(1, ch));
            }
            // Operator
            else {
                
                string op1 = st.top();
                st.pop();
                
                string op2 = st.top();
                st.pop();
                
                string temp = op1 + op2 + ch;
                st.push(temp);
            }
        }
        
        return st.top();
    }
};