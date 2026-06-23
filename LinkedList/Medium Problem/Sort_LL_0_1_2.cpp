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
    ListNode* sortList(ListNode* head) {

        int count0 = 0;
        int count1 = 0;
        int count2 = 0;


        // Step 1: Count 0,1,2
        ListNode* temp = head;

        while(temp != NULL){

            if(temp->data == 0){
                count0++;
            }
            else if(temp->data == 1){
                count1++;
            }
            else{
                count2++;
            }

            temp = temp->next;
        }


        // Step 2: Replace values
        temp = head;


        while(temp != NULL){

            if(count0 > 0){

                temp->data = 0;
                count0--;

            }
            else if(count1 > 0){

                temp->data = 1;
                count1--;

            }
            else{

                temp->data = 2;
                count2--;

            }

            temp = temp->next;
        }


        return head;
    }
};