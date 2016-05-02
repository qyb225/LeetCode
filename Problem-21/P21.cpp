#include <iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
};

ListNode * Solution::mergeTwoLists(ListNode * l1, ListNode * l2) {
    ListNode * ans = NULL;
    ListNode * head1 = l1, * head2 = l2;
    ListNode * head = NULL;
    if (l1 == NULL) {
        return l2;
    }
    else if (l2 == NULL) {
        return l1;
    }

    else if (l1 == NULL && l2 == NULL) {
        return NULL;
    }

    if (head1 -> val < head2 -> val) {
        head = head1;
        head1 = head1 -> next;
    }
    else {
        head = head2;
        head2 = head2 -> next;
    }
    ans = head;

    while (head1 != NULL && head2 != NULL) {
        if (head1 -> val < head2 -> val) {
            head -> next = head1;
            head1 = head1 -> next;
            head = head -> next;
        }
        else {
            head -> next = head2;
            head2 = head2 -> next;
            head = head -> next;
        }
    }
    if (head1 == NULL) {
        head -> next = head2;
    }
    else if (head2 == NULL) {
        head -> next = head1;
    }

    return ans;
}