#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums);
};

bool Solution::containsDuplicate(vector<int>& nums) {
    vector<int> v = nums;
    if (v.size() == 0)
        return false;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size() - 1; ++i) {
        if (v[i] == v[i + 1])
            return true;
    }
    return false;
}