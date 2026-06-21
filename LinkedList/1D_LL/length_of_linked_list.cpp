#include<iostream>
#include<vector>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int val) {
        data = val;
        next = NULL;
    }
};

class Solution {
public:
    int getLength(ListNode* head) {

        ListNode* temp = head;
        int count = 0;

        while(temp != NULL) {
            count++;
            temp = temp->next;
        }

        return count;
    }
};