#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};

ListNode * Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode * ans = l1, * head = l2, *follow = NULL, * mid = NULL;

    while (l1 != NULL && l2 != NULL) {
        l1 -> val = l1 -> val + l2 -> val;
        follow = l1;
        l1 = l1 -> next;
        l2 = l2 -> next;
        if (follow -> val >= 10) {
            follow -> val -= 10;
            if (l1 != NULL) {
                l1 -> val += 1;
            }
            else {
                l1 = new ListNode(1);
                follow -> next = l1;
            }
        }
    }
    if (l1 == NULL) {
        follow -> next = l2;
    }
    while (l1 != NULL) {
        follow = l1;
        l1 = l1 -> next;
        if (follow -> val >= 10) {
            follow -> val -= 10;
            if (l1 != NULL) {
                l1 -> val += 1;
            }
            else {
                l1 = new ListNode(1);
                follow -> next = l1;
            }
        }
    }
    return ans;
}
