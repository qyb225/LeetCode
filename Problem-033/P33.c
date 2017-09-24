#include <stdio.h>

int search(int* nums, int numsSize, int target);

int main() {
    int nums[7] = {3, 4, 5, 6, 0, 1, 2};
    printf("nums: {3, 4, 5, 6, 0, 1, 2}\n");
    int i;
    for (i = -1; i < 8; ++i) {
        printf("search: %2d >>> index: %2d\n", i, search(nums, 7, i));
    }
    return 0;
}

int search(int* nums, int numsSize, int target) {
    if (numsSize == 1) {
        return nums[0] == target ? 0 : -1;
    }
    int lo = 0, hi = numsSize;
    while (lo < hi) {
        int mi = (lo + hi) >> 1;
        if (nums[mi] == target) {
            return mi;
        }
        if (nums[mi] <= nums[hi - 1]) {
            if (target > nums[mi] && target <= nums[hi - 1]) {
                lo = mi + 1;
            } else {
                hi = mi;
            }
        } else {
            if (target >= nums[lo] && target < nums[mi]) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
    }
    return -1;
}