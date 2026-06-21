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
    ListNode* insertAtHead(ListNode* &head, int X) {

        // create new node
        ListNode* newNode = new ListNode(X);

        // connect new node to old head
        newNode->next = head;

        // update head
        head = newNode;

        return head;
    }
};

