## 21. Merge Two Sorted Lists

---
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
```cpp
// Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
```
> **Examples:**

> Given list1 = [1, 5, 6]; list2 = [2, 4, 7, 8]

> Should return [1, 2, 4, 5, 6, 7, 8]