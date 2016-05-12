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
    ListNode* deleteDuplicates(ListNode* head);
};

ListNode * Solution::deleteDuplicates(ListNode * head) {
    ListNode * ans = head;
    ListNode * follow = head;
    if (ans == NULL || ans -> next == NULL) {
        return ans;
    }
    head = head -> next;
    while (head != NULL) {
        if (head -> val == follow -> val) {
            head = head -> next;
            follow -> next = head;
        }
        else {
            follow = head;
            head = head -> next;
        }
    }
    return ans;
}
