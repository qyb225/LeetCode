#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums);
};

vector<vector<int>> Solution::threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    if (nums.size() < 3) return ans;
    vector<int> p;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; ++i) {
        int forw = i + 1;
        int bakw = nums.size() - 1;
        p.push_back(nums[i]);
        while (forw < bakw) {
            int sum = nums[i] + nums[bakw] + nums[forw];
            if (sum < 0) ++forw;
            else if (sum > 0) --bakw;
            else {
                p.push_back(nums[forw++]);
                p.push_back(nums[bakw--]);
                ans.push_back(p);
                while (forw < bakw && nums[forw] == p[1]) ++forw;
                while (forw < bakw && nums[bakw] == p[2]) --bakw;
                p.pop_back();
                p.pop_back();
            }
        }
        p.pop_back();
        while (i < nums.size() - 2 && nums[i + 1] == nums[i]) ++i;
    }
    return ans;
}