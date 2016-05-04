## 24. Swap Nodes in Pairs

---

Given a linked list, swap every two adjacent nodes and return its head.

```cpp
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
```

**For example:**

> Given **1->2->3->4**.

> You should return the list as **2->1->4->3**.

**Note:** Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.



