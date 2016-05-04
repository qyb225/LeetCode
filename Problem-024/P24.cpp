#include <iostream>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head);
};

ListNode * Solution::swapPairs(ListNode* head) {
    ListNode * ans = head;
    ListNode * follow = head;
    ListNode * front = NULL, * swap = NULL;
    if (follow == NULL) {
        return ans;
    }
    if (follow -> next == NULL) {
        return ans;
    }
    else {
        front = follow -> next;
    }
    follow -> next = front -> next;
    front -> next = follow;
    ans = front;
    swap = follow;
    if (follow -> next != NULL) {
        follow = follow -> next;
        front = follow -> next;
    }
    else {
        return ans;
    }
    while (front != NULL && follow != NULL) {
        follow -> next = front -> next;
        front -> next = follow;
        swap -> next = front;
        swap = follow;
        if (follow -> next != NULL) {
            follow = follow -> next;
            front = follow -> next;
        }
        else {
            return ans;
        }
    }
    return ans;
}