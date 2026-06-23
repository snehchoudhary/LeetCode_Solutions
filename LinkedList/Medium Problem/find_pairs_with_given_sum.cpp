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

