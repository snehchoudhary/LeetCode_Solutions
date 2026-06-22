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

//In this case we are getting the exact middle node itself but we want the prev node before middle one to delete the middle so we modify the middleNode function.

// class Solution {
// public:

//     ListNode* middleNode(ListNode* head){
//         ListNode* slow = head;
//         ListNode* fast = head;

//       while(fast != NULL){

//         fast = fast -> next;
//         if (fast != NULL){
//             fast = fast -> next;
//             slow = slow -> next;
//         }

//     }

//         return slow;
//     }
//     ListNode* deleteMiddle(ListNode* head) {
//         ListNode* prev = middleNode(head);
//         prev -> next = mid -> next;

//         return head;
//     }
    
// };


//Modified function of middle 
// class Solution {
// public:

//     ListNode* deleteMiddle(ListNode* head) {

        // if list has only one node
        // if(head == NULL || head->next == NULL){
        //     return NULL;
        // }


        // find node before middle
        // ListNode* slow = head;
        // ListNode* fast = head;

        // while(fast->next != NULL && fast->next->next != NULL){

        //     slow = slow->next;
        //     fast = fast->next->next;

        // }


        // slow is now previous node of middle
        // ListNode* temp = slow->next;


        // delete middle node
        // slow->next = temp->next;


        // delete temp;


        // return head;
//     }
// };

//THE ABOVE SOLUTION GAVE WRONG ANSWER


class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        // only one node
        if(head == NULL || head->next == NULL){
            return NULL;
        }


        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;


        while(fast != NULL && fast->next != NULL){

            prev = slow;
            slow = slow->next;
            fast = fast->next->next;

        }


        // slow is the middle node
        prev->next = slow->next;


        delete slow;


        return head;
    }
};