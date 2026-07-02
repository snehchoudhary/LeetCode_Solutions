#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;


class Solution {
public:
    string postToInfix(string postExp) {
        
        stack<string> st;
        
        for (int i = 0; i < postExp.size(); i++) {
            
            char ch = postExp[i];
            
            // If operand
            if ((ch >= 'A' && ch <= 'Z') ||
                (ch >= 'a' && ch <= 'z') ||
                (ch >= '0' && ch <= '9')) {
                
                st.push(string(1, ch));
            }
            // If operator
            else {
                
                string op2 = st.top();
                st.pop();
                
                string op1 = st.top();
                st.pop();
                
                string temp = "(" + op1 + ch + op2 + ")";
                st.push(temp);
            }
        }
        
        return st.top();
    }
};
