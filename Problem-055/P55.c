int canJump(int* nums, int numsSize) {
    if (numsSize < 2) {
        return 1;
    }
    int i, count = 0;
    for (i = numsSize - 1; i >= 0; --i) {
        if (nums[i] >= count) {
            count = 0;
        }
        ++count;
    }
    return count == 1;
}