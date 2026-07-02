#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
public:
    string postToPre(string postfix) {
        
        stack<string> st;
        
        for (int i = 0; i < postfix.size(); i++) {
            
            char ch = postfix[i];
            
            // Operand
            if ((ch >= 'A' && ch <= 'Z') ||
                (ch >= 'a' && ch <= 'z') ||
                (ch >= '0' && ch <= '9')) {
                
                st.push(string(1, ch));
            }
            // Operator
            else {
                
                string op2 = st.top();
                st.pop();
                
                string op1 = st.top();
                st.pop();
                
                string temp = ch + op1 + op2;
                st.push(temp);
            }
        }
        
        return st.top();
    }
};