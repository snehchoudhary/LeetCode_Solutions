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
    ListNode *detectCycle(ListNode *&head) {
        //check for loop
        ListNode*slow = head;
        ListNode*fast = head;

        //check cycle
        while(fast!=NULL && fast->next){
            slow = slow->next;
            fast=fast->next->next;

            if (slow == fast){
                break;
            }
        }

        //no cycle
        if (fast == NULL || fast->next == NULL){
            return NULL;
        }

        //find cycle entry
        slow = head;
        while (slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;    //cycle start
    }
};