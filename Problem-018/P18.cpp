#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target);
    int _find(vector<vector<int>>&, vector<int>&);
};

vector<vector<int>> Solution::fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    int n = nums.size();
    if (n <= 3) return ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 3; ++i) {
        vector<int> v;
        v.push_back(nums[i]);
        for (int j = i + 1; j < n - 2; ++j) {
            v.push_back(nums[j]);
            int forw = j + 1;
            int bakw = n - 1;
            while (forw < bakw) {
                if (nums[i] + nums[j] + nums[forw] + nums[bakw] < target)
                    ++forw;
                else if (nums[i] + nums[j] + nums[forw] + nums[bakw] > target)
                    --bakw;
                else {
                    v.push_back(nums[forw++]);
                    v.push_back(nums[bakw--]);
                    if (_find(ans, v) == -1) ans.push_back(v);
                    v.pop_back();
                    v.pop_back();
                }
            }
            v.pop_back();
        }
    }
    return ans;
}

int Solution::_find(vector<vector<int>>& v, vector<int>& e) {
    for (int i = v.size() - 1; i >= 0; --i) {
        if (e == v[i]) return i;
    }
    return -1;
}