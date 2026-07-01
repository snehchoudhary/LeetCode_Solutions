#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class ArrayStack {
public:

    int arr[10];
    int topIndex;

    ArrayStack() {
        topIndex = -1;
    }
    
    void push(int x) {

        if(topIndex >= 9)
            return;

        topIndex++;
        arr[topIndex] = x;
    }
    
    int pop() {

        if(topIndex == -1)
            return 0;

        int value = arr[topIndex];
        topIndex--;

        return value;
    }
    
    int top() {

        if(topIndex == -1)
            return 0;

        return arr[topIndex];
    }
    
    bool isEmpty() {

        return topIndex == -1;
    }
};