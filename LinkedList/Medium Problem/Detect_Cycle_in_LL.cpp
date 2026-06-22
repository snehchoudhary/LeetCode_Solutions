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
    bool hasCycle(ListNode *&head) {
        ListNode*slow = head;
        ListNode*fast = head;

        while(fast!=NULL){
            fast = fast->next;
            if(fast!=NULL){
                fast = fast->next;
                slow = slow->next;
            }
            //check for loop
            if(fast == slow){
                return true;
            }
        }
        return false;
    }
};