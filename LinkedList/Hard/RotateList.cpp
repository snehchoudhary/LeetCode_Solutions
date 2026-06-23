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

    // Step 1: Get length
    int getLength(ListNode*head){
        int length = 0;
        while(head){
            ++length; head = head->next;
        }
        return length;
    }

    // Actual rotation
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return 0;
        int length = getLength(head);
        int actualRotateK = (k%length);
        if(actualRotateK == 0){
            return head;
        }

        // find new last node
        int newLastNodePos = length - actualRotateK -1;

        // traverse to new last node
        ListNode*newLastNode = head;
        for(int i=0; i<newLastNodePos; i++){
            newLastNode = newLastNode->next;
        }
        
        // break and form new head
        ListNode*newHead = newLastNode->next;
        newLastNode->next = NULL;
        
        //connect tail to old head
        ListNode*It = newHead;
        while(It->next){
            It = It->next;
        }
        It->next = head;
        return newHead;
    }
};