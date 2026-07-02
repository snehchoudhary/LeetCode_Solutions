#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class ArrayQueue {
public:

    int arr[10];
    int currentSize;
    int start;
    int end;

    ArrayQueue() {
        currentSize = 0;
        start = -1;
        end = -1;
    }
    
    void push(int x) {

        if (currentSize == 10) 
            return;

        if (currentSize == 0) {
            start = 0;
            end = 0;
        }
        else {
            end = (end + 1) % 10;
        }

        arr[end] = x;
        currentSize++;
    }
    
    int pop() {

        if (currentSize == 0) 
            return -1;

        int element = arr[start];

        if (currentSize == 1) {
            start = -1;
            end = -1;
        }
        else {
            start = (start + 1) % 10;
        }

        currentSize--;

        return element;
    }
    
    int peek() {

        if (currentSize == 0) 
            return -1;

        return arr[start];
    }
    
    bool isEmpty() {

        return currentSize == 0;
    }
};