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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode*h1 = head; //odd linked list
        ListNode*h2 = head->next; // even linked lsit
        ListNode*evenHead = h2 ; // storing even indexed head

        while(h2 && h2->next){
            h1->next = h2->next;
            h2->next = h2->next->next;
            h1 = h1->next;
            h2 = h2->next;
        }
        // the two independent prepard list has been regrouped
        h1->next = evenHead;
        return head;
    }
};