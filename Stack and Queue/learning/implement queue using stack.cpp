#include <stack>
using namespace std;

class StackQueue {
public:

    stack<int> input;
    stack<int> output;


    StackQueue() {
    }
    

    void push(int x) {

        input.push(x);   // O(1)

    }
    

    int pop() {

        if(output.empty()) {

            while(!input.empty()) {

                output.push(input.top());
                input.pop();
            }
        }


        if(output.empty())
            return -1;


        int value = output.top();

        output.pop();

        return value;
    }
    

    int peek() {

        if(output.empty()) {

            while(!input.empty()) {

                output.push(input.top());
                input.pop();
            }
        }


        if(output.empty())
            return -1;


        return output.top();
    }
    

    bool isEmpty() {

        return input.empty() && output.empty();
    }
};