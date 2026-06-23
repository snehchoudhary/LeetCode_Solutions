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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return NULL;

        // Step 1: Check if we have k nodes ahead
        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (!temp) return head;  
            temp = temp->next;
        }

        // Step 2: Reverse first k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        for (int i = 0; i < k; i++) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Step 3: Recursively reverse remaining list
        head->next = reverseKGroup(curr, k);

        // prev is the NEW head of this reversed group
        return prev;
    }
};