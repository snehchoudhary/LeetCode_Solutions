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
    ListNode *deleteHead(ListNode *&head) {

        // if list is empty
        if(head == NULL){
            return NULL;
        }

        ListNode* temp = head;

        // move head to next node
        head = head->next;

        // remove connection
        if(head != NULL){
            head->prev = NULL;
        }

        temp->next = NULL;
        temp->prev = NULL;

        delete temp;

        return head;
    }
};