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
      int getLength (ListNode*head){
        int length =0;
        ListNode*temp = head;
        while(temp !=NULL){
            length ++;
            temp = temp->next;
        }
        return length;
      }
    ListNode* middleNode(ListNode* head) {
        ListNode*slow = head;
        ListNode*fast = head;
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                slow=slow->next;
            }
        }
        return slow;
    }
};