#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class LinkedListStack {

public:

    // Node structure
    class Node {
    public:
        int data;
        Node* next;

        Node(int x) {
            data = x;
            next = NULL;
        }
    };


    Node* topNode;


    // Constructor
    LinkedListStack() {
        topNode = NULL;
    }


    // Push element
    void push(int x) {

        Node* newNode = new Node(x);

        newNode->next = topNode;
        topNode = newNode;
    }


    // Pop element
    int pop() {

        if(topNode == NULL)
            return -1;


        int value = topNode->data;

        Node* temp = topNode;

        topNode = topNode->next;

        delete temp;

        return value;
    }


    // Get top element
    int top() {

        if(topNode == NULL)
            return -1;


        return topNode->data;
    }


    // Check empty
    bool isEmpty() {

        return topNode == NULL;
    }
};