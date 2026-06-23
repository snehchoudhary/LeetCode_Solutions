#include <iostream>
using namespace std;

/*
Definition of singly linked list:
*/
class ListNode {
public:
    int data;
    ListNode* next;

    ListNode() : data(0), next(nullptr) {}

    ListNode(int x) {
        data = x;
        next = nullptr;
    }

    ListNode(int x, ListNode* next) {
        data = x;
        this->next = next;
    }
};

class Solution {
public:

    int addHelper(ListNode* temp){
        if (temp == NULL)
            return 1;
    
        int carry = addHelper(temp->next);
        temp->data += carry;

        if (temp->data < 10){
            return 0;
        }

        temp->data = 0;
        return 1;
    }

    ListNode* addOne(ListNode* head) {
        int carry = addHelper(head);

        if (carry == 1){
            ListNode* newNode = new ListNode(1);
            newNode->next = head;
            head = newNode;
        }

        return head;
    }
};