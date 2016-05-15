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
    ListNode* rotateRight(ListNode* head, int k);
};

ListNode * Solution:: rotateRight(ListNode * head, int k) {
    int length = 0, count = 0;
    ListNode * ans = head, * tail = NULL;
    if (head == NULL) {
        return ans;
    }
    while (head -> next!= NULL) {
        ++length;
        head = head -> next;
    }
    ++length;
    if (length == 1) {
        return head;
    }
    if (length == k) {
        return ans;
    }

    k %= length;
    tail = head;
    length -= k;
    head = ans;
    tail -> next = head;

    while (count < length - 1) {
        head = head -> next;
        ++count;
    }

    ans = head -> next;
    head -> next = NULL;
    return ans;
}
