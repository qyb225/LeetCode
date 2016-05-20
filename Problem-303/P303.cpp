#include <iostream>
#include <vector>

using namespace std;

class NumArray {
private:
    vector<int> n;
public:
    NumArray(vector<int> &nums);
    int sumRange(int i, int j);
};

NumArray::NumArray(vector<int> &nums) {
    n = nums;
}
int NumArray::sumRange(int i, int j) {
    int sum = 0;
    for (int k = i; k <= j; ++k) {
        sum += n[k];
    }
    return sum;
}

int main() {
    vector<int> n;
    NumArray numArray(n);
	
    n.push_back(-2);
    n.push_back(0);
    n.push_back(3);
    n.push_back(-5);
    n.push_back(2);
    n.push_back(-1);
	
    cout << numArray.sumRange(0, 2) << endl;
    cout << numArray.sumRange(2, 5) << endl;
    cout << numArray.sumRange(0,5) << endl;
    return 0;
}
