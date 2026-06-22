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
    int findLengthOfLoop(ListNode *head) {
     ListNode* slow = head;
     ListNode* fast = head;

     while (fast != NULL && fast->next != NULL){
        slow = slow-> next;
        fast = fast -> next -> next;

        if (slow == fast){
            int count = 1;
            
            fast = fast -> next;
            while (fast != slow){
                count++;
                fast = fast -> next;
            }
            return count;
        }
     }
     return 0;
    }
};