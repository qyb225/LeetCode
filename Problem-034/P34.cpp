#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target);
};

vector<int> Solution::searchRange(vector<int>& nums, int target) {
    vector<int> ans;
    int lo = 0, hi = nums.size();
    if (0 == hi || target < nums[0] || target > nums[hi - 1]) {
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
    int mi;
    while (lo < hi) {
        mi = (lo + hi) >> 1;
        if (target < nums[mi])
            hi = mi;
        else
            lo = mi + 1;
    }
    int an1 = lo - 1;
    cout << an1 << endl;
    if (nums[an1] != target) {
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    } else {
        lo = -1;
        hi = nums.size() - 1;
        while (lo < hi) {
            mi = ((lo + hi) >> 1) + 1;
            if (target > nums[mi])
                lo = mi;
            else
                hi = mi - 1;
        }
    }
    int an2 = hi + 1;
    cout << an2 << endl;
    ans.push_back(an2);
    ans.push_back(an1);
    return ans;
}