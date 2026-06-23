#include<iostream>
using namespace std;

// definition of doubly LL
class ListNode {
    public:

    int data;
    ListNode* next;
    ListNode* prev;

    //constructor
    ListNode(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution {
public:
    ListNode * removeDuplicates(ListNode *head) {
     
        ListNode* temp = head;
        while (temp != NULL && temp ->next != NULL){
            ListNode* nextNode = temp -> next;
            while (nextNode != NULL && nextNode->data == temp -> data){
                ListNode* duplicate = nextNode;
                nextNode = nextNode->next;
                free(duplicate);
            }
            temp -> next = nextNode;
            if(nextNode != NULL) nextNode->prev = temp;

            temp = temp->next;
        }
        return head;
    }
};