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

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* ans = l1;
    ListNode* l1Front = NULL;
    while (l1 && l2) {
        l1->val += l2->val;
        l1Front = l1;
        l1 = l1->next;
        l2 = l2->next;
        if (l1Front->val > 9) {
            l1Front->val -= 10;
            if (l1) {
                l1->val += 1;
            } else {
                l1 = l1Front->next = new ListNode(1);
            }
        }
    }
    if (l1) {
        while (l1 && l1->val > 9) {
            l1->val -= 10;
            if (l1->next) {
                l1->next->val += 1;
            } else {
                l1->next = new ListNode(1);
            }
            l1 = l1->next;
        }
    } else if (l2) {
        l1Front->next = l2;
        while (l1Front && l1Front->val > 9) {
            l1Front->val -= 10;
            if (l1Front->next) {
                l1Front->next->val += 1;
            } else {
                l1Front->next = new ListNode(1);
            }
            l1Front = l1Front->next;
        }
    }
    return ans;
}
