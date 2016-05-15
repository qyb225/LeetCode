## 61. Rotate List

---

Given a list, rotate the list to the right by k places, where k is non-negative.

```cpp
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
```

**For example:**

> Given **1->2->3->4->5->NULL** and **k = 2**

> return **4->5->1->2->3->NULL**.
