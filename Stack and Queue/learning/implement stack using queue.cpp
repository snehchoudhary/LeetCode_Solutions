#include <queue>
using namespace std;

class QueueStack {
public:

    queue<int> q;


    QueueStack() {
    }
    

    void push(int x) {

        int size = q.size();

        q.push(x);


        while(size--) {

            q.push(q.front());
            q.pop();
        }
    }
    

    int pop() {

        if(q.empty())
            return -1;


        int value = q.front();

        q.pop();

        return value;
    }
    

    int top() {

        if(q.empty())
            return -1;


        return q.front();
    }
    

    bool isEmpty() {

        return q.empty();
    }
};