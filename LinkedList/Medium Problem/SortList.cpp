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
    ListNode*findMid(ListNode*head){
         ListNode*slow = head;
        ListNode*fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode*merge(ListNode*left, ListNode*right){
        if(left == 0) return right;
        if(right == 0) return left;

        ListNode*ans =new ListNode(-1);
        ListNode*mptr = ans;

        while(left && right){
            if(left->val < right->val){
                mptr->next = left;
                mptr = left;
                left = left->next;
            }
            else{
                mptr->next= right;
                mptr = right;
                right = right->next;
            }
        }
        if(left){
            mptr->next = left;
        }
        if(right){
            mptr->next = right;
        }
        return ans->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==0 || head->next == 0){
            return head;
        }
        //break LL into two halves using mid node
        ListNode*mid = findMid(head);
        ListNode*left = head;
        ListNode*right = mid->next;
        mid->next = 0;

        //sort recursively
        left = sortList(left);
        right = sortList(right);

        //merge both left and right ll
        ListNode*mergedLL = merge(left, right);
        return mergedLL;
    }
};