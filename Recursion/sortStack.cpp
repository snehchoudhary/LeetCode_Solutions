#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
public:

    void insertSorted(stack<int>&st, int num){
        //base case
        if(st.empty() || st.top() < num){
            st.push(num);
            return ;
        }
        int top = st.top();
        st.pop();

        insertSorted(st, num);
        st.push(top);
    }
    void sortStack(stack<int> &st) {
        // Your code goes here
        //base case
        if(st.empty()) {
            return;
        }
        //remove top element
        int num = st.top();
        st.pop();

        //sort remaining stack
        sortStack(st);

        //insert removed element correctly
        insertSorted(st, num);
    }
};