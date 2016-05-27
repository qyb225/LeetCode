#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k);
};

void Solution::rotate(vector<int>& nums, int k) {
    int i = 0;
    vector<int>::iterator j;
    k = k % nums.size();
    while (i < k) {
        j = nums.end() - 1;
        nums.insert(nums.begin(), *j);
        nums.pop_back();
        ++i;
    }
}