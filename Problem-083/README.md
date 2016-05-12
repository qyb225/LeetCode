## 83. Remove Duplicates from Sorted List

---

Given a sorted linked list, delete all duplicates such that each element appear only once.

```cpp
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
```

**For example:**

> Given **1->1->2**, return **1->2**.

> Given **1->1->2->3->3**, return **1->2->3**.