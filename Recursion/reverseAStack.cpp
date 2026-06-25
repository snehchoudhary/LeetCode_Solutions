#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
public:

    //insert element at bottom
    void insertAtBottom(stack<int>& st, int element){
      //insert at bottom
      if(st.empty()){
        st.push(element);
            return;
        
      }
      //remove top
      int top = st.top();
      st.pop();

      //recursive call
      insertAtBottom(st, element);

      //put removed element back
      st.push(top);
     }
    void reverseStack(stack<int> &st) {
        // Your code goes here

        //base case
        if (st.empty()){
        return;
        }
         // remove top element
        int element = st.top();
        st.pop();

        // reverse remaining stack
        reverseStack(st);

        // insert removed element at bottom
        insertAtBottom(st, element);
    }
};