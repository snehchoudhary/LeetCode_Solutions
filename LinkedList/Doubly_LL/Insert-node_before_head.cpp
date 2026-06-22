#include<iostream>
using namespace std;

// definition of doubly LL
class ListNode {
    public:

    int data;
    ListNode* next;
    ListNode* prev;

    //constructor
    ListNode(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution {
public:
    ListNode* insertBeforeHead(ListNode* head, int X) {
        // Your code goes here
        ListNode* newNode = new ListNode (X);
        newNode -> next = head;
        newNode -> prev = NULL;
        
        if (head != NULL){
            head -> prev = newNode;
        }
        return newNode;
    }
};