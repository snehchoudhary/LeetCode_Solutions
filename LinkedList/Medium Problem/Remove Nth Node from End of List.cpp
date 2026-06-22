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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return nullptr;

        // Step 1: Find length of list
        int count = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        // Step 2: If n is equal to length, delete the head
        if (n == count) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Step 3: Traverse to node before the one to delete
        temp = head;
        for (int i = 1; i < count - n; i++) {
            temp = temp->next;
        }

        // Step 4: Delete nth node
        ListNode* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;

        return head;
    }
};
