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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      if (!headA || !headB) return NULL;

      ListNode *a = headA;
      ListNode *b = headB;

      while(a != b) {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
      }
      return a;      //intersection node
    }
};


//Key Idea : Why does this work?

//Suppose:

//A length = x + c

//B length = y + c

//where:

//x = nodes before intersection in A
//y = nodes before intersection in B
//c = common part

//Pointer A travels:

//x + c + y

//Pointer B travels:

//y + c + x

//Both travel equal distance.

//Therefore:

//a == b

//at the intersection.

//Complexity

//Time:

//O(n + m)

//Space:

//O(1)

//This is the optimal approach.