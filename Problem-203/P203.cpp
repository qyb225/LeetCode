
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val);
};

ListNode* Solution::removeElements(ListNode* head, int val) {
    ListNode *ans = NULL, *behind = NULL;
    if (head == NULL)
        return NULL;
    while (head -> val == val && head -> next != NULL) {
        head = head -> next;
    }
    
    if (head -> next == NULL) {
        if (head -> val == val)
            return NULL;
        else
            return head;
    }

    ans = head;
    behind = head;
    head = head -> next;
    while (head != NULL) {
        if (head -> val == val) {
            head = head -> next;
            behind -> next = head;
        }
        else {
            behind = head;
            head = head -> next;
        }
    }
    return ans;
}