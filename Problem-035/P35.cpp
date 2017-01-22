#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target);
};

int Solution::searchInsert(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size();
    while (lo < hi) {
        int mi = (lo + hi) >> 1;
        if (target < nums[mi])
            hi = mi;
        else
            lo = mi + 1;
    }
    if (lo > 0 && target == nums[lo - 1])
        return lo - 1;
    else
        return lo;
}