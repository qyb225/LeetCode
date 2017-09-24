/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize);
void quickSort(struct Interval* intervals, int lo, int hi);


struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    struct Interval* ans = NULL;
    if (intervalsSize < 1) {
        *returnSize = 0;
        return ans;
    }
    
    quickSort(intervals, 0, intervalsSize);
    
    ans = (struct Interval*) malloc(sizeof(struct Interval*) * intervalsSize);
    ans[0] = intervals[0];
    int i = 1;
    *returnSize = 1;
    while (i < intervalsSize) {
        if (intervals[i].start > ans[*returnSize - 1].end) {
            ans[*returnSize] = intervals[i];
            *returnSize += 1;
        } else if (ans[*returnSize - 1].end < intervals[i].end) {
            ans[*returnSize - 1].end = intervals[i].end;
        }
        ++i;
    }
    return ans;
}

void quickSort(struct Interval* intervals, int lo, int hi) {
    if (hi - lo < 2) {
        return;
    }
    int piv = hi - 1;
    int i = lo, j = piv - 1;
    while (i <= j) {
        while (i <= j && intervals[i].start < intervals[piv].start) {
            ++i;
        }
        while (i <= j && intervals[j].start >= intervals[piv].start) {
            --j;
        }
        if (i < j) {
            struct Interval temp = intervals[i];
            intervals[i] = intervals[j];
            intervals[j] = temp;
        }
    }
    struct Interval temp = intervals[i];
    intervals[i] = intervals[piv];
    intervals[piv] = temp;
    
    quickSort(intervals, lo, i);
    quickSort(intervals, i + 1, hi);
}