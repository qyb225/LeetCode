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
    ListNode* removeNthFromEnd(ListNode * head, int n);
};

ListNode* Solution::removeNthFromEnd(ListNode * head, int n) {
    int count = 0, length;
    ListNode * ans = head, * follow = NULL;

    while (head != NULL) {
        count++;
        head = head -> next;
    }
    
    if (n == count) {
        return ans -> next;
    }
    length = count - n;
    count = 0;
    head = ans;
    follow = NULL;

    while (count < length) {
        follow = head;
        head = head -> next;
        count++;
    }
    follow -> next = head -> next;
    return ans;
}
