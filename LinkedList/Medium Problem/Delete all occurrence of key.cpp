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
    ListNode* deleteAllOccurrences(ListNode* head, int target) {
        ListNode* temp = head;

        while (temp != NULL) {
            if (temp->data == target) {

                ListNode* nextNode = temp->next;
                ListNode* prevNode = temp->prev;

                // if deleting head
                if (temp == head) {
                    head = nextNode;
                }

                if (nextNode != NULL) {
                    nextNode->prev = prevNode;
                }

                if (prevNode != NULL) {
                    prevNode->next = nextNode;
                }

                delete temp;

                temp = nextNode;
            }
            else {
                temp = temp->next;
            }
        }

        // important: fix new head prev pointer
        if (head != NULL) {
            head->prev = NULL;
        }

        return head;
    }
};