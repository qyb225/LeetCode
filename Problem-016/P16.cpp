#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target);
    int _abs(int);
};

int Solution::threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int ans = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < nums.size(); ++i) {
        int sec = i + 1;
        int thi = nums.size() - 1;
        while (sec < thi) {
            int add = nums[i] + nums[sec] + nums[thi];
            if (add - target == 0) return add;
            if (_abs(add - target) < _abs(ans - target)) ans = add;
            if (add - target < 0) ++sec;
            else --thi;
        }
    }
    return ans;
}

int Solution::_abs(int a) {
    if (a >= 0) return a;
    else return -1 * a;
}
