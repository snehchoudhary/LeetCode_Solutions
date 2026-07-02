#include <stack>
using namespace std;

class MinStack {
public:

    stack<long long> st;
    long long mini;


    MinStack() {

        mini = LLONG_MAX;
    }
    

    void push(int val) {

        long long x = val;


        if(st.empty()) {

            st.push(x);
            mini = x;
        }

        else if(x >= mini) {

            st.push(x);
        }

        else {

            // store modified value
            st.push(2*x - mini);

            // update minimum
            mini = x;
        }
    }
    

    void pop() {

        if(st.empty())
            return;


        long long x = st.top();

        st.pop();


        // modified value found
        if(x < mini) {

            mini = 2*mini - x;
        }
    }
    

    int top() {

        if(st.empty())
            return -1;


        long long x = st.top();


        // return actual value
        if(x < mini)
            return mini;


        return x;
    }
    

    int getMin() {

        return mini;
    }
};