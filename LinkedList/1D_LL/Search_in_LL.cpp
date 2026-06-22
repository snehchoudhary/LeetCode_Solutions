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
    bool searchKey(ListNode* head, int key) {
        // Your code goes here

        ListNode*temp = head;
        while (temp != NULL){
            if (temp-> val == key){
                return true;
            }
            temp = temp -> next;
        }
        return false;
    }
};