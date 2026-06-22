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

    ListNode* reverseUsingRecursion(ListNode* prev, ListNode* curr){
        //base case
        if(curr == NULL){
            return prev;
        }
        // 1 case will be solved by us 
        ListNode* nextNode = curr -> next;
        curr -> next = prev;
        prev =curr;
        curr = nextNode;

        //rest will be handled by recursion 
        ListNode* recursionKaAns = reverseUsingRecursion(prev, curr);
        return recursionKaAns;
    }
    ListNode* reverseDLL(ListNode* head) {
        // Your code goes here
        ListNode* prev = NULL;
        ListNode* curr = head;
        return reverseUsingRecursion(prev, curr);
    }
};