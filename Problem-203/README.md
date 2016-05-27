##203. Remove Linked List Elements

---

Remove all elements from a linked list of integers that have value **val**.

```cpp
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
```

**Example:**

> 1. Given: **1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6**, val = **6**

> 2. Return: **1 --> 2 --> 3 --> 4 --> 5**

