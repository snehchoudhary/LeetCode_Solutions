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

   ListNode*reverseUsingRecursion(ListNode*prev, ListNode*curr){
    //base case
    if(curr == NULL){
        return prev;
    }
        //1case is solved by me
        ListNode*nextNode = curr->next;
        curr->next=prev;
        prev = curr;
        curr = nextNode;

        //rest recursion will handle
        return reverseUsingRecursion(prev, curr);
   }
    
    ListNode*middleNode(ListNode*head){      //left most mid
        ListNode*slow = head;
        ListNode*fast = head;
        while(fast->next != NULL){
            fast = fast->next;
            if(fast->next !=NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }
    bool compareList(ListNode*head1, ListNode*head2){
        while(head1!=NULL && head2!=NULL){
            if(head1->data != head2->data){
                return false;
            }
            else {
                head1 = head1->next;
                head2 = head2->next;
            }
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        ListNode*midNode = middleNode(head);
        ListNode* head2 = midNode->next;    //giiven name to right most mid

        //2 separate LL
        midNode->next = NULL;
        //reverse the second half
        ListNode*prev = NULL;
        ListNode*curr = head2;
        head2 = reverseUsingRecursion(prev, curr);
        //compare both LL
        bool ans = compareList(head, head2);
        return ans;

    }
};