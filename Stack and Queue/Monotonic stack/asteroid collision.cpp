#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
      stack <int> st;

      for (auto ast: asteroids) {
        bool destroy = false;        // nothing is destroyed initially

        while (!st.empty() && st.top() > 0 && ast < 0){
            if (abs(ast) > st.top()){
                st.pop();
            }
            else if (abs(ast) == st.top()) {
                st.pop();
                destroy = true;
                break;
            }
            else {
                destroy = true;
                break;
            }
        }
        if (!destroy) {
            st.push(ast);
        }
      }
      //convert stack -> vector
      vector <int> ans(st.size());

      for (int i =st.size() - 1; i >= 0 ; i--){
        ans[i] = st.top();
        st.pop();
      }
      return ans;
     }
};