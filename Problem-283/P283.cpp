#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums);
};

void Solution::moveZeroes(vector<int>& nums) {
    int count = 0;
    vector<int>::iterator iter;
    iter = nums.begin();
    while (iter != nums.end()) {
        if (*iter == 0) {
            ++count;
            iter = nums.erase(iter);
        }
        else
            ++iter;
    }
    for (int i = 0; i < count; ++i)
        nums.push_back(0);
}