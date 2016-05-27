
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head);
};

ListNode* Solution::reverseList(ListNode* head) {
    if (head == NULL || head -> next == NULL)
        return head;
    ListNode* ans = head, *front = head -> next;
    head -> next = NULL;
    while (front) {
        ans = front -> next;
        front -> next = head;
        head = front;
        front = ans;
    }
    return head;
}
