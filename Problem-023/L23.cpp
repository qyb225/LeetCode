#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(NULL) {} 
};

class Solution {
public:
    ListNode* merge2Lists(ListNode* lists1, ListNode* lists2);
    ListNode* mergeKLists(vector<ListNode*>& lists);
};

ListNode* Solution::mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0) {
        return NULL;
    } else if (lists.size() < 2) {
        if (lists[0]) {
            return lists[0];
        }
        return NULL;
    } else if (lists.size() == 2) {
        return merge2Lists(lists[0], lists[1]);
    } else {
        vector<ListNode*> temp;
        int i = 0;
        while (i < lists.size()) {
            if (i != lists.size() - 1) {
                temp.push_back(merge2Lists(lists[i], lists[i + 1]));
                i += 2;
            } else {
                temp.push_back(lists[i]);
                i += 1;
            }
        }
        return mergeKLists(temp);
    }
}

ListNode* Solution::merge2Lists(ListNode* lists1, ListNode* lists2) {
    if (!lists1 || !lists2) {
        if (lists1) {
            return lists1;
        }
        if (lists2) {
            return lists2;
        }
        return NULL;
    }

    ListNode *l1Head = lists1, *l2Head = lists2;
    ListNode *ans = NULL, *temp = NULL;
    if (l1Head->val < l2Head->val) {
        ans = l1Head;
        l1Head = l1Head->next;
        ans->next = NULL;
    } else {
        ans = l2Head;
        l2Head = l2Head->next;
        ans->next = NULL;
    }
    temp = ans;
    while (l1Head && l2Head) {
        if (l1Head->val < l2Head->val) {
            temp->next = l1Head;
            l1Head = l1Head->next;
            temp = temp->next;
            temp->next = NULL;
        } else {
            temp->next = l2Head;
            l2Head = l2Head->next;
            temp = temp->next;
            temp->next = NULL;
        }
    }
    if (l1Head) {
        temp->next = l1Head;
    }
    if (l2Head) {
        temp->next = l2Head;
    }

    return ans;
}

int main() {
    ListNode* temp1 = new ListNode(0);
    ListNode* temp2 = new ListNode(1);
    ListNode* temp3 = new ListNode(2);
    ListNode* l1 = temp1;
    ListNode* l2 = temp2;
    ListNode* l3 = temp3;
    for (int i = 1; i < 30; ++i) {
        ListNode* temp = new ListNode(i);
        if (i % 3 == 1) {
            temp1->next = temp;
            temp1 = temp1->next;
        } else if (i % 3 == 2) {
            temp2->next = temp;
            temp2 = temp2->next;
        } else {
            temp3->next = temp;
            temp3 = temp3->next;
        }
    }
    vector<ListNode*> lists;
    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);
    Solution s = Solution();
    ListNode* ans = s.mergeKLists(lists);
    while (ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;

    return 0;
}