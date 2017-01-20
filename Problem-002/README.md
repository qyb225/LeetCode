## 2. Add Two Numbers 

---

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.


```cpp
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
```

**For example:**

> **Input**: (2 -> 4 -> 3) + (5 -> 6 -> 4)

> **Output**: 7 -> 0 -> 8
