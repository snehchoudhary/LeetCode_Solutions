#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class LinkedListQueue {

public:

    class Node {
    public:
        int data;
        Node* next;

        Node(int x) {
            data = x;
            next = NULL;
        }
    };


    Node* front;
    Node* rear;


    // Constructor
    LinkedListQueue() {
        front = NULL;
        rear = NULL;
    }


    // Insert element
    void push(int x) {

        Node* newNode = new Node(x);


        // first element
        if(rear == NULL) {

            front = rear = newNode;
            return;
        }


        rear->next = newNode;
        rear = newNode;
    }



    // Remove element
    int pop() {

        if(front == NULL)
            return -1;


        int value = front->data;


        Node* temp = front;

        front = front->next;


        // queue becomes empty
        if(front == NULL)
            rear = NULL;


        delete temp;


        return value;
    }



    // Get front element
    int peek() {

        if(front == NULL)
            return -1;


        return front->data;
    }



    // Check empty
    bool isEmpty() {

        return front == NULL;
    }

};